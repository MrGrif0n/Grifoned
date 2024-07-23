/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:22:32 by gkonstan          #+#    #+#             */
/*   Updated: 2023/08/19 14:45:08 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_ulen(unsigned int d);

int	ft_print_uint(unsigned long n)
{
	unsigned long		len;
	int					i;
	long unsigned int	j;

	len = 10;
	i = ft_ulen(n);
	j = 0;
	if (n == INT_MIN + j)
	{
		ft_print_dig((n / 10) - 1);
		n = -(n % 10);
	}
	if (n < len)
		ft_putchar(n + '0');
	else
	{
		ft_print_uint(n / 10);
		ft_print_uint(n % 10);
	}
	return (i);
}

int	ft_ulen(unsigned int dec)
{
	unsigned int	i;

	i = 0;
	if (!dec)
		i++;
	while (dec)
	{
		dec /= 10;
		i++;
	}
	return (i);
}
