/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:22:31 by gkonstan          #+#    #+#             */
/*   Updated: 2023/08/19 14:45:08 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*The C library function 
  int memcmp(const void *str1, const void *str2, size_t n)) 
  compares the first n bytes of memory area str1 and memory area str2.*/

int	ft_memcmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*comp1;
	unsigned char	*comp2;
	int				f;
	int				i;

	i = 0;
	f = 0;
	comp1 = (unsigned char *) str1;
	comp2 = (unsigned char *) str2;
	while (n > 0)
	{
		if (comp1[f] != comp2[f])
			return (comp1[f] - comp2[f]);
		f++;
		n--;
	}
	return (i);
}
