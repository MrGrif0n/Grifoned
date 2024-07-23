/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:22:32 by gkonstan          #+#    #+#             */
/*   Updated: 2023/08/19 14:45:09 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*The strlcat() function appends the NUL-terminated string src to the end of
  dst. It will append at most size - strlen(dst) - 1 bytes,
  NUL-terminating the result. */

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d;
	size_t	s;

	d = 0;
	s = 0;
	while (src[s] != '\0')
		s++;
	if (size != 0)
	{
		while (dst[d] != '\0' && d < size)
			d++;
		i = 0;
		while (src[i] != '\0' && d + i + 1 < size)
		{
			dst[i + d] = src[i];
			i++;
		}
		if (d != size)
			dst[i + d] = '\0';
	}
	return (d + s);
}
