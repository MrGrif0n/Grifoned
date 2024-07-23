/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan  < gkonstan@student.42vienn>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 01:00:00 by gkonstan          #+#    #+#             */
/*   Updated: 2024/02/04 14:46:47 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	check_symbol(char c)
{
	if (c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'E' && c != 'W'
		&& c != ' ' && c != '\n')
		return (0);
	return (1);
}

static void	free_exit(t_create *create, char *str)
{
	if (str)
		free(str);
	ft_free_exit(create, 1, "Error\nInvalid file format");
}

void	save_map_3(t_create *create, int height, int i, int no_next_line)
{
	if (height >= create->map_info.height)
		return ;
	while (i < create->map_info.width - 1)
	{
		create->map_info.map[height][i] = ' ';
		i++;
	}
	if (no_next_line)
	{
		height++;
		save_map_3(create, height, 0, 0);
	}
	return ;
}

void	save_map_2(t_create *create, char *line, int height)
{
	int			i;
	int			j;
	static int	flag = 0;

	i = 0;
	j = 0;
	if (flag == 1 && line[0] != '\n')
		free_exit(create, line);
	if (line[0] == '\n')
		flag = 1;
	while (line[i] != '\0')
	{
		if (!check_symbol(line[i]))
			free_exit(create, line);
		else
		{
			if (line[i] != '\n')
				create->map_info.map[height][i] = line[i];
			else
				save_map_3(create, height, i, 0);
		}
		i++;
	}
}

void	save_map(const char *map_name, t_create *create)
{
	int		i;
	char	*line;
	int		fd;
	int		height;

	height = 0;
	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_free_exit(create, 1, "Error\nInvalid file");
	line = skip_until_map(fd);
	while (line != NULL)
	{
		save_map_2(create, line, height);
		free(line);
		line = get_next_line(fd);
		if (line)
			i = ft_strlen(line);
		if (line == NULL)
			save_map_3(create, height, i, 1);
		height++;
	}
	close(fd);
}
