#include "grifoned.h"

void initialize_konami_code(t_data *data)
{
    data->konami_code[0] = XK_Up;
    data->konami_code[1] = XK_Up;
    data->konami_code[2] = XK_Down;
    data->konami_code[3] = XK_Down;
    data->konami_code[4] = XK_Left;
    data->konami_code[5] = XK_Right;
    data->konami_code[6] = XK_Left;
    data->konami_code[7] = XK_Right;
    data->konami_code[8] = XK_b;
    data->konami_code[9] = XK_a;
    data->konami_index = 0;
}

bool check_konami_code(t_data *data, KeySym keysym)
{
    if (keysym == data->konami_code[data->konami_index])
    {
        data->konami_index++;
        if (data->konami_index == 10)
        {
            return true;
        }
    }
    else
    {
        data->konami_index = 0;
    }
    return false;
}

bool is_konami_key(KeySym keysym)
{
    return keysym == XK_Up || keysym == XK_Down || keysym == XK_Left ||
           keysym == XK_Right || keysym == XK_b || keysym == XK_a;
}

void grab_special_keys(Display *display, Window window)
{
    int i;
    KeyCode keycode;
    KeySym keys_to_grab[] = {
        XK_Alt_L, XK_Alt_R,
        XK_Tab,
        XK_Super_L, XK_Super_R,
        XK_F1, XK_F2, XK_F3, XK_F4, XK_F5,
        XK_F6, XK_F7, XK_F8, XK_F9, XK_F10,
        XK_F11, XK_F12,
    };
    int num_keys = sizeof(keys_to_grab) / sizeof(KeySym);

    for (i = 0; i < num_keys; i++)
    {
        keycode = XKeysymToKeycode(display, keys_to_grab[i]);
        XGrabKey(display, keycode, AnyModifier, window, True, GrabModeAsync, GrabModeAsync);
    }

    // Grab all control keys
    for (keycode = 0; keycode < 255; keycode++)
    {
        if (XkbKeycodeToKeysym(display, keycode, 0, 0) == XK_Control_L ||
            XkbKeycodeToKeysym(display, keycode, 0, 0) == XK_Control_R)
        {
            XGrabKey(display, keycode, AnyModifier, window, True, GrabModeAsync, GrabModeAsync);
        }
    }
    
    // Grab the entire keyboard to prevent special keys from functioning
    XGrabKeyboard(display, window, True, GrabModeAsync, GrabModeAsync, CurrentTime);
}