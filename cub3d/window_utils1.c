/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan  < gkonstan@student.42vienn>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 01:00:00 by gkonstan          #+#    #+#             */
/*   Updated: 2024/02/04 19:24:59 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_sign(float f)
{
	if (f < 0.0f)
	{
		if (f > -0.000001)
			return (0);
		else
			return (-1);
	}
	else
	{
		if (f < 0.000001f)
			return (0);
		else
			return (1);
	}
}

void	ft_ray_initial_calculations(t_create *create, t_ray *r, float v)
{
	r->dx = cos(v);
	r->dy = -sin(v);
	r->sx = ft_sign(r->dx);
	r->sy = ft_sign(r->dy);
	r->vert_x = (int) create->player.x;
	if (r->sx > 0)
		r->vert_x += 1.0f;
	r->hor_y = (int) create->player.y;
	if (r->sy > 0)
		r->hor_y += 1.0f;
}

float	ft_save_color(t_create *create, float dist, int color_idx, float w)
{
	create->txt_idx = color_idx;
	create->txt_w = w;
	return (dist);
}

void	init_pos(t_create *create)
{
	int	i;
	int	j;

	i = -1;
	while (++i < create->map_info.height)
	{
		j = -1;
		while (create->map_info.map[i][++j])
		{
			if (ft_strchr("NSWE", create->map_info.map[i][j]))
			{
				create->player.x = (float) j + 0.5f;
				create->player.y = (float) i + 0.5f;
				find_angle_view(create, create->map_info.map[i][j]);
				return ;
			}
		}
	}
}

void	find_angle_view(t_create *create, char c)
{
	if (c == 'N')
		create->player.view = 0.5f * M_PI;
	else if (c == 'S')
		create->player.view = -0.5f * M_PI;
	else if (c == 'W')
		create->player.view = 0.0f * M_PI;
	else if (c == 'E')
		create->player.view = 1.0f * M_PI;
}
