/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan  < gkonstan@student.42vienn>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 01:00:00 by gkonstan          #+#    #+#             */
/*   Updated: 2024/02/04 19:30:32 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_ray_next_step_calculation(t_create *create, t_ray *r)
{
	if (r->sx != 0)
	{
		r->vert_y = create->player.y + r->dy / r->dx
			* (r->vert_x - create->player.x);
		r->vert_dist = sqrt(pow(create->player.x - r->vert_x, 2.0)
				+ pow(create->player.y - r->vert_y, 2.0));
		r->vert_w = r->vert_y - (int) r->vert_y;
		if (r->sx > 0)
			r->vert_w = 1 - r->vert_w;
	}
	else
		r->vert_dist = INFINITY;
	if (r->sy != 0)
	{
		r->hor_x = create->player.x + r->dx / r->dy
			* (r->hor_y - create->player.y);
		r->hor_dist = sqrt(pow(create->player.x - r->hor_x, 2.0)
				+ pow(create->player.y - r->hor_y, 2.0));
		r->hor_w = r->hor_x - (int) r->hor_x;
		if (r->sy < 0)
			r->hor_w = 1 - r->hor_w;
	}
	else
		r->hor_dist = INFINITY;
}

float	ft_ray(t_create *create, float v)
{
	t_ray	r;

	ft_ray_initial_calculations(create, &r, v);
	while (1)
	{
		ft_ray_next_step_calculation(create, &r);
		if (r.vert_dist < r.hor_dist)
		{
			if (create->map_info.map[(int)r.vert_y][(int)r.vert_x + (r.sx - 1)
				/ 2] == '1')
				return (ft_save_color(create, r.vert_dist, r.sx + 1, r.vert_w));
			else
				r.vert_x += r.sx;
		}
		else
		{
			if (create->map_info.map[(int)r.hor_y + (r.sy - 1)
					/ 2][(int)r.hor_x] == '1')
				return (ft_save_color(create, r.hor_dist, r.sy + 2, r.hor_w));
			else
				r.hor_y += r.sy;
		}
	}
}

void	ft_line(t_create *create, int w, float dist)
{
	unsigned int	*dst;
	unsigned int	*src;
	unsigned int	h;
	float			src_f;
	float			d_shift;

	h = (float) WIN_HEIGHT / dist;
	src_f = 0.0f;
	d_shift = (float) ft_get_txt_height(create) / h;
	if (h > WIN_HEIGHT)
	{
		src_f = 0.5f * (h - WIN_HEIGHT) / h * ft_get_txt_height(create);
		h = WIN_HEIGHT;
	}
	src = (unsigned int *) ft_get_txt_addr(create);
	src += (int)((float) create->txt_w * ft_get_txt_width(create));
	dst = (unsigned int *) create->img.addr + w + (WIN_HEIGHT - h)
		/ 2 * WIN_WIDTH;
	while (h-- > 0)
	{
		*dst = *(src + ((int)src_f) * ft_get_txt_width(create));
		dst += WIN_WIDTH;
		src_f += d_shift;
	}
}

void	ft_ray_cast(t_create *create)
{
	int		x;
	float	dv;
	float	v;

	v = create->player.view - FOV / 2;
	dv = FOV / (WIN_WIDTH - 1);
	x = -1;
	while (++x < WIN_WIDTH)
	{
		ft_line(create, x, ft_ray(create, v) * cos(create->player.view - v));
		v += dv;
	}
}
