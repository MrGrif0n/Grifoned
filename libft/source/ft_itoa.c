/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:22:31 by gkonstan          #+#    #+#             */
/*   Updated: 2023/08/19 14:45:08 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*Converts an integer value to a null-terminated
  string using the specified base and stores the result in the array
  given by str parameter.*/

static size_t	ft_counter(size_t	nbr)
{
	size_t	i;

	i = 0;
	if (!nbr)
		i++;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i + 1);
}

static char	*ft_putinstr(int minus, size_t nbr, int i)
{
	char	*p;

	p = malloc(sizeof(char) * i);
	if (!p)
		return (NULL);
	if (minus)
		p[0] = '-';
	p[--i] = '\0';
	if (!nbr && i--)
		p[i] = '0' + 0;
	while (nbr > 0 && i--)
	{
		p[i] = '0' + nbr % 10;
		nbr = nbr / 10;
	}
	return (p);
}

char	*ft_itoa(int n)
{
	long long int	nbr;
	int				minus;
	int				i;
	char			*p;

	if (!n && n != 0)
		return (0);
	nbr = n;
	i = 0;
	minus = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
		minus++;
	}
	i = i + ft_counter(nbr);
	p = ft_putinstr(minus, nbr, i);
	return (p);
}

/*
int main(void)
{
	int i = 531;
	printf("String: %s\n", ft_itoa(i));
	return (0);	
}*/
