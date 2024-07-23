/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan  < gkonstan@student.42vienn>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 01:00:00 by gkonstan          #+#    #+#             */
/*   Updated: 2024/02/06 16:22:42 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	check_xpm_extension(char *path)
{
	int	i;

	i = ft_strlen(path) - 4;
	if (ft_strncmp(&path[i], ".xpm", 4) != 0)
		return (1);
	return (0);
}

void	init_structs(t_create *create)
{
	create->mlx = mlx_init();
	if (create->mlx == NULL)
		ft_free_exit(create, 1, "Error\nmlx_init failed, please try again");
	create->win = NULL;
	create->map_info.width = 0;
	create->map_info.height = 0;
	create->map_info.map = NULL;
	create->north.texture.addr = NULL;
	create->east.texture.addr = NULL;
	create->south.texture.addr = NULL;
	create->west.texture.addr = NULL;
	create->north.img = NULL;
	create->east.img = NULL;
	create->south.img = NULL;
	create->west.img = NULL;
	create->player.x = 0;
	create->player.y = 0;
	create->player.view = 0;
	create->colors.floor = -1;
	create->colors.ceiling = -1;
	create->sub = 1;
}

int	check_all_info_initialized(t_create *create)
{
	if (!create->north.img || !create->east.img || !create->south.img
		|| !create->west.img || !create->map_info.map
		|| create->colors.floor == -1
		|| create->colors.ceiling == -1
		|| !create->player.x || !create->player.y
		|| !create->map_info.width || !create->map_info.height)
		return (0);
	return (1);
}

int	ft_check_for_lenght(char *file)
{
	const char	*base;

	base = ft_strrchr(file, '/');
	if (base != NULL)
		base = base + 1;
	else
		base = file;
	if (ft_strlen(base) < 5)
		return (1);
	return (0);
}

int	check_extension(t_create *create, char *file, char *ext)
{
	int	file_len;
	int	ext_len;
	int	i;

	file_len = ft_strlen(file);
	ext_len = ft_strlen(ext);
	i = 0;
	if (HIDDEN == 1 && ft_hidden(file))
		return (1);
	else if (HIDDEN == 0)
	{
		if (ft_check_for_lenght(file))
			return (1);
	}
	while (ext[i])
	{
		if (file[file_len - 1 - i] != ext[ext_len - 1 - i])
			return (1);
		i++;
	}
	return (0);
	create->map_info.map = NULL;
}
