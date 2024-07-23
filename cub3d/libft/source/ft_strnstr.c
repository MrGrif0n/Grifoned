/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:22:32 by gkonstan          #+#    #+#             */
/*   Updated: 2023/08/19 14:45:09 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*The strstr() function locates the first occurrence	of the null-terminated
  string little in the null-terminated string big.*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t length)
{
	size_t	i;
	size_t	c;
	char	*var_hay;

	i = 0;
	var_hay = (char *)haystack;
	if (needle[0] == '\0')
		return (var_hay);
	if (!length)
		return (0);
	while (var_hay[i] != '\0' && i < length)
	{
		c = 0;
		while (var_hay[i + c] == needle[c] && i + c < length)
		{
			if (needle [c + 1] == '\0')
				return (var_hay + i);
			c++;
		}
		i++;
	}
	return (0);
}
