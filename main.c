#include "hacked.h"


int main(void)
{
    t_data data;
    Window root;
    XEvent event;
    Cursor invisible_cursor;

    // Initialize display
    data.display = XOpenDisplay(NULL);
    if (!data.display)
    {
        return (1);
    }

    // Get the screen's width and height
    root = DefaultRootWindow(data.display);
    data.screen_width = DisplayWidth(data.display, DefaultScreen(data.display));
    data.screen_height = DisplayHeight(data.display, DefaultScreen(data.display));

    // Create a window using Xlib
    data.x11_window = XCreateSimpleWindow(data.display, root, 0, 0,
                                          data.screen_width, data.screen_height,
                                          1, BlackPixel(data.display, 0),
                                          WhitePixel(data.display, 1));

    // Map the window to ensure it is displayed
    XMapWindow(data.display, data.x11_window);
    XFlush(data.display);

    // Wait a short time to ensure the window is mapped
    usleep(100000);

    // Set window properties to make it fullscreen
    set_fullscreen(data.display, data.x11_window);

    // Move the mouse to the center of the screen
    XWarpPointer(data.display, None, data.x11_window, 0, 0, 0, 0, data.screen_width / 2, data.screen_height / 2);
    XFlush(data.display);

    // Create and set the invisible cursor
    invisible_cursor = create_invisible_cursor(data.display, root);
    XDefineCursor(data.display, data.x11_window, invisible_cursor);

    // Select input events
    XSelectInput(data.display, data.x11_window, PointerMotionMask | KeyPressMask);

    // Initialize Konami code sequence
    initialize_konami_code(&data);

    // Grab special keys to prevent their default behavior
    grab_special_keys(data.display, data.x11_window);

    // Event loop
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

    XUngrabKeyboard(data.display, CurrentTime);
    XDestroyWindow(data.display, data.x11_window);
    XFreeCursor(data.display, invisible_cursor);
    XCloseDisplay(data.display);
    return (0);
}
