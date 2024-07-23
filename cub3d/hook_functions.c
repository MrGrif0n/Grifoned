/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:16:33 by ngjokaj           #+#    #+#             */
/*   Updated: 2024/02/02 20:29:49 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <complex.h>
#include <math.h>

void	free_map(t_map_info *map_info)
{
	int	i;

	i = 0;
	if (map_info == NULL || map_info->map == NULL)
		return ;
	while (i < map_info->height)
	{
		free(map_info->map[i]);
		i++;
	}
	free(map_info->map);
}

int	close_window(t_create *create)
{
	if (create->win)
		mlx_destroy_window(create->mlx, create->win);
	if (create->img.img && create->east.img)
		mlx_destroy_image(create->mlx, create->east.img);
	if (create->img.img && create->south.img)
		mlx_destroy_image(create->mlx, create->south.img);
	if (create->img.img && create->west.img)
		mlx_destroy_image(create->mlx, create->west.img);
	if (create->img.img && create->north.img)
		mlx_destroy_image(create->mlx, create->north.img);
	if (create->mlx)
	{
		mlx_destroy_display(create->mlx);
		free(create->mlx);
	}
	if (create->map_info.map)
		free_map(&create->map_info);
	if (create->garbage.line != NULL)
		free(create->garbage.line);
	if (create->garbage.split != NULL)
		ft_free_strarray(create->garbage.split);
	if (create)
		free(create);
	get_next_line(-1);
	exit(0);
}

void	move_player(t_create *create, int direction)
{
	float	dist;
	float	dx;
	float	dy;
	float	angle;

	angle = create->player.view + direction * M_PI / 2;
	dx = 0.3 * cos(angle);
	dy = 0.3 * sin(angle);
	dist = ft_ray(create, ft_sign(dy) * M_PI / 2);
	if (dist * dist < dy * dy)
		dy = 0.0f;
	dist = ft_ray(create, (1 - (ft_sign(dx) + 1) / 2) * M_PI);
	if (dist * dist < dx * dx)
		dx = 0.0f;
	dist = ft_ray(create, angle);
	if (dist * dist < dy * dy + dx * dx)
		if (ft_sign(dy) * ft_sign(dx) != 0)
			dy = 0.0f;
	create->player.x += dx;
	create->player.y -= dy;
}

int	key_hook(int keycode, t_create *create)
{
	if (keycode == XK_Escape)
		close_window(create);
	else if (keycode == 119)
		move_player(create, 0);
	else if (keycode == 100)
		move_player(create, 1);
	else if (keycode == 115)
		move_player(create, 2);
	else if (keycode == 97)
		move_player(create, 3);
	else if (keycode == 65361)
		create->player.view -= 0.02f * M_PI;
	else if (keycode == 65363)
		create->player.view += 0.02f * M_PI;
	else if (keycode == 102)
	{
		if (create->sub == 1)
			create->sub = 0;
		else
			create->sub = 1;
	}
	render_loop(create);
	return (0);
}
