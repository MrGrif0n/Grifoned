/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:22:31 by gkonstan          #+#    #+#             */
/*   Updated: 2023/08/19 14:45:08 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*The C library function void *memchr(const void *str, int c, size_t n)
  searches for the first occurrence of the character c (an unsigned char)
  in the first n bytes of the string pointed to, by the argument str.*/

void	*ft_memchr(const	void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

/*int main (void)
{
   const char str[] = "http://wwwtutorialspointcom";
   const char ch = '\0';
   char *ret;

   ret = memchr(str, ch, ft_strlen(str));

   printf("memString after |%c| is - |%s|\n", ch, ret);

   return(0);
}*/
