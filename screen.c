#include "grifoned.h"

void set_fullscreen(Display *display, Window window)
{
    Atom wm_state = XInternAtom(display, "_NET_WM_STATE", False);
    Atom fullscreen = XInternAtom(display, "_NET_WM_STATE_FULLSCREEN", False);

    XEvent xev;
    memset(&xev, 0, sizeof(xev));
    xev.type = ClientMessage;
    xev.xclient.window = window;
    xev.xclient.message_type = wm_state;
    xev.xclient.format = 32;
    xev.xclient.data.l[0] = 1; // 1 to add, 0 to remove
    xev.xclient.data.l[1] = fullscreen;
    xev.xclient.data.l[2] = 0;
    xev.xclient.data.l[3] = 0;
    xev.xclient.data.l[4] = 0;

    XSendEvent(display, DefaultRootWindow(display), False,
               SubstructureNotifyMask, &xev);
    XFlush(display);
}

#include <X11/Xlib.h>
#include <X11/Xutil.h>

// Function to create an invisible cursor
Cursor create_invisible_cursor(Display *display, Window root)
{
    Pixmap bitmap_no_data;
    XColor black;
    static char no_data[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

    // Create the bitmap (1x1 pixel)
    bitmap_no_data = XCreateBitmapFromData(display, root, no_data, 8, 8);
    if (bitmap_no_data == None)
    {
        fprintf(stderr, "Failed to create bitmap for invisible cursor\n");
        return None;
    }

    black.red = black.green = black.blue = 0;

    // Create the invisible cursor using the bitmap
    Cursor invisible_cursor = XCreatePixmapCursor(display, bitmap_no_data, bitmap_no_data, &black, &black, 0, 0);
    if (invisible_cursor == None)
    {
        fprintf(stderr, "Failed to create invisible cursor\n");
    }

    // Free the bitmap data
    XFreePixmap(display, bitmap_no_data);

    return invisible_cursor;
}

