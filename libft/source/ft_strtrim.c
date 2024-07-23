/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:22:31 by gkonstan          #+#    #+#             */
/*   Updated: 2023/08/19 14:45:08 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*strtrim removes all whitespace characters from the beginning and the end of a 
string.
As whitespace is counted everything for which isspace(3) returns true.*/

static size_t	ft_find(const char c, char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char	const *s1, char const *set)
{
	char	*mem;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!s1 || !set)
		return (0);
	while (ft_find(s1[i], set) == 1)
		i++;
	while (s1[i + len])
		len++;
	while ((i + len) >= 1 && s1[i + len - 1] != '\0'
		&& ft_find(s1[i + len - 1], set) == 1 && len != 0)
		len--;
	mem = malloc(len + 1);
	if (!mem)
		return (0);
	mem[len] = '\0';
	while (len-- != 0)
		mem[len] = (char)s1[i + len];
	return (mem);
}
