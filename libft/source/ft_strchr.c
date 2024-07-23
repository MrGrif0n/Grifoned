/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:22:32 by gkonstan          #+#    #+#             */
/*   Updated: 2023/08/19 14:45:08 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*The C library function char *strchr(const char *str, int c) searches for the
 first occurrence of the character c (an unsigned char) in the string pointed
 to by the argument str.*/

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != (char) c)
	{
		if (!*s++)
			return (0);
	}
	return ((char *)s);
}
