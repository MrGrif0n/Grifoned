/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:22:32 by gkonstan          #+#    #+#             */
/*   Updated: 2023/08/19 14:45:08 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*The C library function void *calloc(size_t nitems, size_t size)
  allocates the requested memory and returns a pointer to it. 
  The difference in malloc and calloc is that malloc does not set the
  memory to zero where as calloc sets allocated memory to zero.*/

void	*ft_calloc(size_t __nmemb, size_t __size)
{
	void	*i;
	size_t	check;

	check = __nmemb * __size;
	if (__nmemb != 0 && check / __nmemb != __size)
		return (0);
	i = malloc(__nmemb * __size);
	if (!i)
		return (0);
	ft_bzero(i, check);
	return (i);
}
