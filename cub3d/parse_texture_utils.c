/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan  < gkonstan@student.42vienn>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gkonstan          #+#    #+#             */
/*   Updated: 2024/02/04 19:11:45 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	test_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

void	ft_save_to_ea(t_create *create, char *path)
{
	if (create->east.img)
	{
		free(path);
		ft_free_exit(create, 1, "Error\nToo many EA textures");
	}
	if (check_xpm_extension(path))
	{
		free(path);
		ft_free_exit(create, 1, "Error\nInvalid texture extension");
	}
	create->east.img = mlx_xpm_file_to_image(create->mlx, path,
			&create->east.texture.width,
			&create->east.texture.height);
	if (create->east.img == NULL)
	{
		free(path);
		ft_free_exit(create, 1, "Error\nMLX failed to load texture path");
	}
	create->east.texture.addr = mlx_get_data_addr(create->east.img,
			&create->east.texture.bits_per_pixel,
			&create->east.texture.line_length,
			&create->east.texture.endian);
}

void	ft_save_to_no(t_create *create, char *path)
{
	if (create->north.img)
	{
		free(path);
		ft_free_exit(create, 1, "Error\nToo many NO textures");
	}
	if (check_xpm_extension(path))
	{
		free(path);
		ft_free_exit(create, 1, "Error\nInvalid texture extension");
	}
	create->north.img = mlx_xpm_file_to_image(create->mlx, path,
			&create->north.texture.width,
			&create->north.texture.height);
	if (create->north.img == NULL)
	{
		free(path);
		ft_free_exit(create, 1, "Error\nMLX failed to load texture path");
	}
	create->north.texture.addr = mlx_get_data_addr(create->north.img,
			&create->north.texture.bits_per_pixel,
			&create->north.texture.line_length,
			&create->north.texture.endian);
}

void	ft_save_to_so(t_create *create, char *path)
{
	if (create->south.img)
	{
		free(path);
		ft_free_exit(create, 1, "Error\nToo many SO textures");
	}
	if (check_xpm_extension(path))
	{
		free(path);
		ft_free_exit(create, 1, "Error\nInvalid texture extension");
	}
	create->south.img = mlx_xpm_file_to_image(create->mlx, path,
			&create->south.texture.width,
			&create->south.texture.height);
	if (create->south.img == NULL)
	{
		free(path);
		ft_free_exit(create, 1, "Error\nMLX failed to load texture path");
	}
	create->south.texture.addr = mlx_get_data_addr(create->south.img,
			&create->south.texture.bits_per_pixel,
			&create->south.texture.line_length,
			&create->south.texture.endian);
}

void	ft_save_to_we(t_create *create, char *path)
{
	if (create->west.img)
	{
		free(path);
		ft_free_exit(create, 1, "Error\nToo many WE textures");
	}
	if (check_xpm_extension(path))
	{
		free(path);
		ft_free_exit(create, 1, "Error\nInvalid texture extension");
	}
	create->west.img = mlx_xpm_file_to_image(create->mlx, path,
			&create->west.texture.width,
			&create->west.texture.height);
	if (create->west.img == NULL)
	{
		free(path);
		ft_free_exit(create, 1, "Error\nMLX failed to load texture path");
	}
	create->west.texture.addr = mlx_get_data_addr(create->west.img,
			&create->west.texture.bits_per_pixel,
			&create->west.texture.line_length,
			&create->west.texture.endian);
}
