/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:54:08 by ngjokaj           #+#    #+#             */
/*   Updated: 2024/02/02 20:04:23 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	ft_allocate_array(t_create *create)
{
	int		i;

	i = 0;
	while (i < create->map_info.height)
	{
		create->map_info.map[i] = ft_calloc(create->map_info.width + 2,
				sizeof(char));
		if (!create->map_info.map[i])
		{
			while (i > 0)
				free(create->map_info.map[--i]);
			free(create->map_info.map);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	allocate_map(t_create *create, int fd)
{
	char	*first_line;

	first_line = create->garbage.line;
	if (first_line == NULL || first_line[0] == '\0')
	{
		if (first_line)
			free(first_line);
		return (0);
	}
	ft_get_info_map(create, fd, ft_strdup(first_line));
	if ((create->map_info.height <= 0 || create->map_info.height >= MAX_MAP_H)
		|| (create->map_info.width <= 0 || create->map_info.width >= MAX_MAP_W))
		return (0);
	create->map_info.map = ft_calloc(create->map_info.height + 1,
			sizeof(char *));
	if (!create->map_info.map)
		return (0);
	if (!ft_allocate_array(create))
		return (0);
	return (1);
}

void	find_player_dp(t_create	*create)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < create->map_info.height)
	{
		j = 0;
		while (j < create->map_info.width)
		{
			if (create->map_info.map[i][j] == 'N'
				|| create->map_info.map[i][j] == 'S'
					|| create->map_info.map[i][j] == 'E'
						|| create->map_info.map[i][j] == 'W')
			{
				create->player.direction = create->map_info.map[i][j];
				create->player.x = j;
				create->player.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	do_next_func(const char *argv, t_create *create)
{
	save_map(argv, create);
	find_player_dp(create);
}

void	parse_argv(const char *argv, t_create *create)
{
	int		fd;

	create->garbage.line = NULL;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_free_exit(create, 1, "Error\nInvalid file");
	create->garbage.line = get_next_line(fd);
	while (create->garbage.line != NULL)
	{
		if (!parse_texture_and_color(create))
			break ;
		free(create->garbage.line);
		create->garbage.line = get_next_line(fd);
	}
	if ((create->garbage.line == NULL ) || !allocate_map(create, fd)
		|| check_all_textures(create) == 0
		|| !create->map_info.height || !create->map_info.width)
	{
		close(fd);
		ft_free_exit(create, 1, "Error\nInvalid file format or malloc failed");
	}
	close(fd);
	do_next_func(argv, create);
}
