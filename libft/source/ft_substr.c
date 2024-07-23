/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:22:33 by gkonstan          #+#    #+#             */
/*   Updated: 2023/08/19 14:45:09 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*C substring program to find substring of a string and its all substrings. 
  A substring is itself a string that is part of a longer string.*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;

	if (!s)
		return (0);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if ((size_t)len > ft_strlen(s))
		len = ft_strlen(s);
	if (!s)
		return (0);
	s = s + start;
	s1 = malloc(len + 1);
	if (s1 == 0)
		return (0);
	ft_memcpy(s1, s, len);
	s1 += len;
	*s1 = '\0';
	return (s1 - len);
}
