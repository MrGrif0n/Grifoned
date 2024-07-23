/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:22:32 by gkonstan          #+#    #+#             */
/*   Updated: 2023/08/19 14:45:09 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*The C library function void *memcpy(void *dest, const void *src, size_t n) 
  copies n characters from memory area src to memory area dest.*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest1;
	const char	*src1;

	dest1 = (char *)dest;
	src1 = (const char *)src;
	if ((!dest) && (!src))
		return (NULL);
	while (n > 0)
	{
		*dest1++ = *src1++;
		n--;
	}
	return (dest);
}

/*int main()
{
        char dest[22];
        char src[] = "test basic du memcpy !";
   	char *r1= memcpy(dest, src,22);
	char *r2 = ft_memcpy(dest, src, 22);
	if (r1 != r2)
	{
		printf("hier1\n%s", r1);
		printf("\n%s", r2);
	}
	r1 = memcpy("", src, 0);
	r2 = ft_memcpy("", src, 0);

	if (r1 != r2)
		printf("hier2");

	printf("hier3");
   	return(0);

}*/
