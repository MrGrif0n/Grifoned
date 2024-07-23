/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:03:50 by ngjokaj           #+#    #+#             */
/*   Updated: 2024/02/02 20:26:45 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_draw_celling_floor(t_create *create)
{
	unsigned int	*dst;
	unsigned int	i;

	dst = (unsigned int *) create->img.addr;
	i = WIN_HEIGHT * WIN_WIDTH / 2 + 1;
	while (--i > 0)
		*dst++ = create->colors.ceiling;
	i = WIN_HEIGHT * WIN_WIDTH / 2 + 1;
	while (--i > 0)
		*dst++ = create->colors.floor;
}

void	render_loop(t_create *create)
{
	create->img.img = mlx_new_image(create->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (create->img.img == NULL)
		ft_free_exit(create, 1, "Error\nmlx_new_image failed");
	create->img.addr = mlx_get_data_addr(create->img.img,
			&create->img.bits_per_pixel, &create->img.line_length,
			&create->img.endian);
	ft_draw_celling_floor(create);
	ft_ray_cast(create);
	mlx_put_image_to_window(create->mlx, create->win, create->img.img, 0, 0);
	mlx_destroy_image(create->mlx, create->img.img);
	mlx_hook(create->win, 17, 0, close_window, create);
	mlx_hook(create->win, 2, 1L << 0, key_hook, create);
	mlx_loop(create->mlx);
}

int	initialize_window(t_create *create)
{
	create->win = mlx_new_window(create->mlx, WIN_WIDTH, WIN_HEIGHT, "create");
	if (create->win == NULL)
		ft_free_exit(create, 1, "Error\nmlx_new_window failed");
	init_pos(create);
	render_loop(create);
	return (0);
}
