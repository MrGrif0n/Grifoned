#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>
#include <X11/XKBlib.h>
#include <X11/cursorfont.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

#define VIDEO_PATH "./vid/grifoned.mp4"

typedef struct  s_data {
    Display     *display;
    Window      x11_window;
    int         screen_width;
    int         screen_height;
    int         konami_index;
    KeySym      konami_code[10];
}               t_data;

void initialize_konami_code(t_data *data);
bool check_konami_code(t_data *data, KeySym keysym);
bool is_konami_key(KeySym keysym);
void grab_special_keys(Display *display, Window window);
void set_fullscreen(Display *display, Window window);
Cursor create_invisible_cursor(Display *display, Window root);