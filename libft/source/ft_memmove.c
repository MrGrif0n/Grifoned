/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:22:33 by gkonstan          #+#    #+#             */
/*   Updated: 2023/08/19 14:45:09 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*The C library function void *memmove(void *str1, const void *str2, size_t n) 
  copies n characters from str2 to str1, but for overlapping memory blocks, 
  memmove() is a safer approach than memcpy().*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest1;
	char	*src1;
	int		i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dest1 = (char *)dest;
	src1 = (char *)src;
	if (dest < src)
	{
		while (n > 0)
		{
			dest1[i] = src1[i];
			n--;
			i++;
		}
	}
	else
	{
		while (n--)
			*(dest1 + n) = *(src1 + n);
	}
	return (dest);
}
/*
int main()
{
	ft_memmove(((void*)0), ((void*)0), 5);
	memmove(((void*)0), ((void*)0), 5);
}
*/
