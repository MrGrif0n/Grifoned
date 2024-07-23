/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:22:33 by gkonstan          #+#    #+#             */
/*   Updated: 2023/08/19 14:45:09 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*The C library function void *memset(void *str, int c, size_t n) copies
the character c (an unsigned char) to the first n characters of the string
 pointed to, by the argument str.*/

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*biff;

	biff = s;
	while (n > 0)
	{
		*biff = c;
		biff++;
		n--;
	}
	return (s);
}
