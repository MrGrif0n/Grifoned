/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:54:08 by ngjokaj           #+#    #+#             */
/*   Updated: 2024/02/02 20:34:56 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <stdbool.h>

int	check_zero(t_create *create)
{
	int	i;
	int	j;

	i = 0;
	while (i < create->map_info.height)
	{
		j = 0;
		while (j < create->map_info.width)
		{
			if (create->map_info.map[i][j] == '0')
			{
				if (i == 0 || i == create->map_info.height - 1
					|| j == 0 || j == create->map_info.width - 1)
					return (0);
				if (check_spaces_and_null(create, i, j) == 0)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_player_symbol(char c)
{
	if (c != 'N' && c != 'S' && c != 'E' && c != 'W')
		return (0);
	return (1);
}

int	check_spaces_and_null(t_create *create, int i, int j)
{
	if (create->map_info.map[i - 1][j] == ' '
		|| create->map_info.map[i - 1][j] == '\0'
		|| create->map_info.map[i + 1][j] == ' '
		|| create->map_info.map[i + 1][j] == '\0'
		|| create->map_info.map[i][j - 1] == ' '
		|| create->map_info.map[i][j - 1] == '\0'
		|| create->map_info.map[i][j + 1] == ' '
		|| create->map_info.map[i][j + 1] == '\0')
		return (0);
	return (1);
}

int	check_player(t_create *create, int i)
{
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (i < create->map_info.height)
	{
		j = 0;
		while (j < create->map_info.width)
		{
			if (check_player_symbol(create->map_info.map[i][j]))
			{
				if (i == 0 || i == create->map_info.height - 1
					|| j == 0 || j == create->map_info.width - 1)
					return (0);
				if (check_spaces_and_null(create, i, j) == 0)
					return (0);
				player++;
			}
			j++;
		}
		i++;
	}
	return (player);
}

int	check_map(t_create *create)
{
	if (check_zero(create) == 0)
		return (0);
	if (check_player(create, 0) != 1)
		return (0);
	return (1);
}
