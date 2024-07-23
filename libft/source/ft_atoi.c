/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:22:33 by gkonstan          #+#    #+#             */
/*   Updated: 2023/08/19 14:45:09 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*The C library function int atoi(const char *str) converts 
the string argument str to an integer (type int).*/

long int	ft_atoi(const char *str)
{
	int						i;
	int						minus;
	long long int			res;

	i = 0;
	res = 0;
	minus = 1;
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			minus = minus * (-1);
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9') && (str[i] != '\0'))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * minus);
}
