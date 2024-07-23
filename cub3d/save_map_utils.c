/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan  < gkonstan@student.42vienn>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gkonstan          #+#    #+#             */
/*   Updated: 2024/02/06 13:22:51 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	print_map(t_create *create)
{
	int	i;

	i = 0;
	printf("Map (Height: %d, Width: %d):\n",
		create->map_info.height, create->map_info.width);
	while (i < create->map_info.height)
	{
		printf("<%s>\n", create->map_info.map[i]);
		i++;
	}
}

char	*skip_until_map(int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		if (line[i] == '1' || (line[i] == '\n' && i != 0))
			return (line);
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}
