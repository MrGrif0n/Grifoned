/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dig_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:22:32 by gkonstan          #+#    #+#             */
/*   Updated: 2023/08/19 14:45:09 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	ft_putnbr(long long	int nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	ft_putchar(nb + 48);
}

int	ft_print_dig(long long int nbr)
{
	long long int	i;
	long long int	nbr2;

	i = 0;
	nbr2 = nbr;
	if (nbr < 0)
	{
		i++;
		nbr = -nbr;
		write(1, "-", 1);
		nbr2 = -nbr2;
	}
	if (!nbr)
		i++;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	ft_putnbr(nbr2);
	return (i);
}
