/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan  < gkonstan@student.42vienn>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gkonstan          #+#    #+#             */
/*   Updated: 2024/02/05 14:11:23 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "libft/include/libft.h"

static void	ft_free_images(t_create *create)
{
	if (create->img.img)
		mlx_destroy_image(create->mlx, create->img.img);
	if (create->east.img)
		mlx_destroy_image(create->mlx, create->east.img);
	if (create->south.img)
		mlx_destroy_image(create->mlx, create->south.img);
	if (create->west.img)
		mlx_destroy_image(create->mlx, create->west.img);
	if (create->north.img)
		mlx_destroy_image(create->mlx, create->north.img);
}

void	ft_free_exit(t_create *create, int close, char *msg)
{
	if (create->win)
		mlx_destroy_window(create->mlx, create->win);
	ft_free_images(create);
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
	if (msg)
		ft_printf("%s\n", msg);
	get_next_line(-1);
	if (close)
		exit(0);
}
