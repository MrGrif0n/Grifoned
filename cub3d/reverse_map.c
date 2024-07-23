/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:52:03 by ngjokaj           #+#    #+#             */
/*   Updated: 2024/02/02 20:35:06 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	reverse_map_x(t_create *create)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	while (i < create->map_info.height)
	{
		start = 0;
		end = create->map_info.width - 2;
		while (start < end)
		{
			ft_swap(&create->map_info.map[i][start], \
			&create->map_info.map[i][end]);
			start++;
			end--;
		}
		i++;
	}
}
