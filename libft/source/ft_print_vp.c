/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_vp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:22:32 by gkonstan          #+#    #+#             */
/*   Updated: 2023/08/19 14:45:08 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	counter(unsigned long int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n = n / 16;
	}
	return (i);
}

int	ft_print_vp(unsigned long long int n)
{
	int	ret;

	ret = 0;
	if (!n)
	{
		return (write(1, "(nil)", 5));
	}
	ret += ft_print_string("0x");
	if (n != 0)
	{
		ft_print_hex(n, 'x');
		ret += counter(n);
	}
	return (ret);
}
