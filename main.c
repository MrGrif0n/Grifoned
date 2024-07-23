#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#include "./minilibx-linux/mlx.h"
#include "hacked.h"
#include "libft/include/libft.h"

void null_create(t_create *create)
{
    create->mlx = NULL;
    create->win = NULL;
    create->mouse.x = 0;
    create->mouse.y = 0;
}

void init_create(t_create *create)
{
    create->mlx = mlx_init();
    create->mouse.x = (int *)ft_calloc(1, sizeof(int));
    create->mouse.y = (int *)ft_calloc(1, sizeof(int));
    create->screen.x = (int *)ft_calloc (1, sizeof(int));
    create->screen.y = (int *)ft_calloc (1, sizeof(int));
    mlx_get_screen_size(create->mlx, create->screen.x, create->screen.y);
    create->screen.size_x = *create->screen.x;
    create->screen.size_y = *create->screen.y;

    create->win = mlx_new_window(create->mlx, create->screen.size_x, create->screen.size_y, "Hello World!");
    mlx_mouse_move(create->mlx, create->win, create->screen.size_x / 2, create->screen.size_y / 2);
}

//mouse_hook should never let mouse to go out of the window
int mouse_hook(int button, void *param)
{
    t_create *create = (t_create *)param;
 
    int old_x = create->screen.size_x / 2;
	if (x == old_x)
		return (0);
	else if (x < old_x)
		data->player.has_moved += rotate_player(data, -1);
	else if (x > old_x)
		data->player.has_moved += rotate_player(data, 1);
	old_x = x;
	return (0);
}

    //why does mlx_mouse_get_pos() segfault?
    int pos_x = 0;
    int pos_y = 0;



    // int pos_x = 0;
    // pos_x = mlx_mouse_get_pos(create->mlx, create->win, create->mouse.x, create->mouse.y);
    // create->mouse.x_cord = *create->mouse.x;
    // create->mouse.y_cord = *create->mouse.y;

    // if (button == 1)
    // {
        pos_x = mlx_mouse_get_pos(create->mlx, create->win, create->mouse.x, create->mouse.y);
        pos_y = mlx_mouse_get_pos(create->mlx, create->win, create->mouse.x, create->mouse.y);
        create->mouse.x_cord = *create->mouse.x;
        create->mouse.y_cord = *create->mouse.y;
        printf("x: %d, y: %d\n", create->mouse.x_cord, create->mouse.y_cord);
    // }
    return (0);
    button = 0;
    param = NULL;
    create = NULL;
}

void ft_free_create(t_create *create)
{
    if (create->mlx)
        mlx_destroy_window(create->mlx, create->win);
    if (create->mlx)
        mlx_destroy_display(create->mlx);
    free(create);
}

int main()
{
    t_create *create;
    create = (t_create *)ft_calloc(1, sizeof(t_create));

    null_create(create);
    init_create(create);
    // mlx_mouse_hide(create->mlx, create->win);
    mlx_hook(create->win, 0, 0, mouse_hook, create);

    mlx_loop(create->mlx);
    ft_free_create(create);
    return (0);
}