/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_X.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:22:32 by gkonstan          #+#    #+#             */
/*   Updated: 2023/08/19 14:45:08 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_print_hex(unsigned long int n, char bos)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i += ft_print_dig(n);
		return (i);
	}
	if (n >= 16)
	{
		i += ft_print_hex(n / 16, bos);
		i += ft_print_hex(n % 16, bos);
	}
	if (n < 16)
	{
		if (n < 10)
			i += ft_putchar(n + '0');
		if (bos == 'x' && n >= 10)
			i += ft_putchar(n + ('a' - 10));
		if (bos == 'X' && n >= 10)
			i += ft_putchar(n + ('A' - 10));
	}
	return (i);
}
