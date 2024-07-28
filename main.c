#include "grifoned.h"
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

pid_t mplayer_pid = -1;
Cursor invisible_cursor = None;


void play_video(t_data *data)
{
    char mplayer_cmd[256];
    snprintf(mplayer_cmd, sizeof(mplayer_cmd), "mplayer -vo x11 -zoom -x %d -y %d -wid %lu -nosound -loop 0 -really-quiet %s 2>mplayer.log", 
             data->screen_width, data->screen_height, data->x11_window, VIDEO_PATH);

    mplayer_pid = fork();
    if (mplayer_pid == 0) // Child process
    {
        // Redirect stderr to a log file for debugging
        freopen("mplayer.log", "w", stderr);

        // Execute mplayer command
        execlp("sh", "sh", "-c", mplayer_cmd, (char *)NULL);
        perror("execlp");
        _exit(1);
    }
    else if (mplayer_pid < 0) // Fork failed
    {
        perror("fork");
    }
}

void stop_video()
{
    if (mplayer_pid != -1)
    {
        // Terminate the mplayer process
        kill(mplayer_pid, SIGTERM);
        waitpid(mplayer_pid, NULL, 0);
        mplayer_pid = -1;
    }
}

void handle_exit(int sig)
{
    stop_video();
    exit(0);
    sig = 0; // Suppress unused parameter warning
}

void initialize_x11_window(t_data *data)
{
    // Initialize display
    data->display = XOpenDisplay(NULL);
    if (!data->display)
    {
        fprintf(stderr, "Failed to open X display\n");
        exit(1);
    }

    // Get the screen's width and height
    Window root = DefaultRootWindow(data->display);
    data->screen_width = DisplayWidth(data->display, DefaultScreen(data->display));
    data->screen_height = DisplayHeight(data->display, DefaultScreen(data->display));

    // Create a window using Xlib
    data->x11_window = XCreateSimpleWindow(data->display, root, 0, 0,
                                           data->screen_width, data->screen_height,
                                           1, BlackPixel(data->display, 0),
                                           WhitePixel(data->display, 1));

    // Select input events
    XSelectInput(data->display, data->x11_window, StructureNotifyMask);

    // Map the window to ensure it is displayed
    XMapWindow(data->display, data->x11_window);

    // Wait for the window to be fully created and mapped
    XEvent event;
    for (;;)
    {
        XNextEvent(data->display, &event);
        if (event.type == MapNotify)
            break;
    }

    // Flush the display to ensure all operations are completed
    XFlush(data->display);

    // Set window properties to make it fullscreen
    set_fullscreen(data->display, data->x11_window);

    // Move the mouse to the center of the screen
    XWarpPointer(data->display, None, data->x11_window, 0, 0, 0, 0, data->screen_width / 2, data->screen_height / 2);
    XFlush(data->display);

    // Create and set the invisible cursor if not already created
    if (invisible_cursor == None)
    {
        invisible_cursor = create_invisible_cursor(data->display, root);
        if (invisible_cursor == None)
        {
            fprintf(stderr, "Failed to create an invisible cursor\n");
            exit(1);
        }
    }
    XDefineCursor(data->display, data->x11_window, invisible_cursor);

    // Select additional input events
    XSelectInput(data->display, data->x11_window, PointerMotionMask | KeyPressMask);
}

void cleanup_x11_window(t_data *data)
{
    if (data->display)
    {
        XUngrabKeyboard(data->display, CurrentTime);
        XDestroyWindow(data->display, data->x11_window);
        XCloseDisplay(data->display);
        data->display = NULL;
    }
}

int main(void)
{
    t_data data = {0};

    // Set up signal handlers to ensure mplayer is stopped on exit
    signal(SIGINT, handle_exit);
    signal(SIGTERM, handle_exit);

    while (1)
    {
        // Initialize X11 window
        initialize_x11_window(&data);

        // Initialize Konami code sequence
        initialize_konami_code(&data);

        // Grab special keys to prevent their default behavior
        grab_special_keys(data.display, data.x11_window);

        // Play the video
        play_video(&data);

        // Event loop
        XEvent event;
        while (1)
        {
            XNextEvent(data.display, &event);
            if (event.type == MotionNotify)
            {
                int x = event.xmotion.x;
                int y = event.xmotion.y;
                int center_x = data.screen_width / 2;
                int center_y = data.screen_height / 2;

                // Always move the mouse back to the center
                if (x != center_x || y != center_y)
                {
                    XWarpPointer(data.display, None, data.x11_window, 0, 0, 0, 0, center_x, center_y);
                    XFlush(data.display);
                }
            }
            else if (event.type == KeyPress)
            {
                KeySym keysym = XLookupKeysym(&event.xkey, 0);
                if (is_konami_key(keysym))
                {
                    if (check_konami_code(&data, keysym))
                    {
                        break; // Exit the loop if Konami code is detected
                    }
                }
            }
        }

        // Stop the video
        stop_video();

        // Clean up X11 window
        cleanup_x11_window(&data);

        // Uncomment this line to exit after one loop
        // exit(0); 
    }

    return 0;
}
