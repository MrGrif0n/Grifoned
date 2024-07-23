/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan  < gkonstan@student.42vienn>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gkonstan          #+#    #+#             */
/*   Updated: 2024/02/04 18:59:50 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_hidden(char *file)
{
	const char	*base;

	base = ft_strrchr(file, '/');
	if (base != NULL)
		base = base + 1;
	else
		base = file;
	if (base[0] == '.' && base[1] != '\0')
		return (1);
	return (0);
}

void	ft_free_strarray(char **strarray)
{
	int	i;

	i = 0;
	if (strarray == NULL)
		return ;
	while (strarray[i] != NULL)
	{
		free(strarray[i]);
		strarray[i] = NULL;
		i++;
	}
	free(strarray);
}

int	check_all_textures(t_create *create)
{
	if (create->north.texture.addr == NULL
		|| create->north.img == NULL
		|| create->south.texture.addr == NULL
		|| create->south.img == NULL
		|| create->west.texture.addr == NULL
		|| create->west.img == NULL
		|| create->east.texture.addr == NULL
		|| create->east.img == NULL)
		return (0);
	return (1);
}

int	parse_texture_and_color(t_create *create)
{
	char	**split;
	char	*line;
	int		i;

	i = 0;
	split = NULL;
	line = create->garbage.line;
	while (line[i] == ' ')
		i++;
	if (!line || line[i] == '\0')
		return (0);
	if (line[i] == 'N' || line[i] == 'S'
		|| line[i] == 'E' || line[i] == 'W')
		parse_texture(create);
	else if ((line[i] == 'F' || line[i] == 'C') && line[i + 1] == ' ')
		parse_color(create, split);
	else if ((line[i] == 'F' && line[i] == 'C') && line[i + 1] != ' ')
		ft_free_exit(create, 1, "Error\n Invalid identifier");
	else if (line[0] == '\n')
		return (1);
	else if (line[i] == '\n' || line[i] == '1')
		return (0);
	else
		ft_free_exit(create, 1, "Error\nInvalid file format");
	return (1);
}

void	ft_get_info_map(t_create *create, int fd, char *line)
{
	int		height;
	int		width_line;
	int		max_width;
	int		nl;

	nl = 0;
	height = 1;
	width_line = ft_strlen(line);
	max_width = width_line;
	while (line != NULL)
	{
		width_line = ft_strlen(line);
		free(line);
		if (width_line == 1 && nl == 0)
			nl = 1;
		else if (width_line != 1 && nl == 1)
			ft_free_exit(create, 1, "Error\nInvalid file format");
		if (width_line > max_width)
			max_width = width_line;
		if (width_line != 1 && nl == 0)
			height++;
		line = get_next_line(fd);
	}
	create->map_info.height = height;
	create->map_info.width = max_width;
}
