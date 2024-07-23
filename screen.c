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



Cursor create_invisible_cursor(Display *display, Window root)
{
    Pixmap blank;
    XColor dummy;
    char data[1] = {0};
    Cursor cursor;

    blank = XCreateBitmapFromData(display, root, data, 1, 1);
    if (blank == None)
    {
        return None;
    }

    cursor = XCreatePixmapCursor(display, blank, blank, &dummy, &dummy, 0, 0);
    XFreePixmap(display, blank);
    return cursor;
}