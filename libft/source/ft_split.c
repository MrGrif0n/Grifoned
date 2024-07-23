/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan  < gkonstan@student.42vienn>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gkonstan          #+#    #+#             */
/*   Updated: 2024/02/05 19:21:22 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan  < gkonstan@student.42vienn>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gkonstan          #+#    #+#             */
/*   Updated: 2024/02/03 14:46:32 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*In C, the strtok() (in this case split()) function is used to split
  a string into a series of tokens based on a particular delimiter.
  A token is a substring extracted from the original string. */

static int	count_c(char const *s, char c);
static char	**put_array(char **my_array, int counter, char const *s, char c);
static char	*get_str(char const *s, char c);

char	**ft_split(const char *s, char c)
{
	char	**my_array;
	int		counter;

	if (!s || !c)
		return (NULL);
	counter = count_c(s, c);
	my_array = malloc(sizeof(char *) * (counter + 1));
	if (!my_array)
	{
		return (NULL);
	}
	my_array = put_array(my_array, counter, s, c);
	if (my_array == NULL)
	{
		free(my_array);
		return (NULL);
	}
	return (my_array);
}

static int	count_c(char const *s, char c)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (s[z])
	{
		if (s[z] != c && !i)
			i++;
		if (s[z] == c && s[z + 1] != c && s[z + 1] != '\0')
			i++;
		z++;
	}
	return (i);
}

static	int	save_2_lines(char *s, char c, char *tmp)
{
	int	i;

	i = 0;
	while (s[i] == c)
		i++;
	i += ft_strlen(tmp);
	return (i);
}

static char	**put_array(char **my_array, int counter, char const *s, char c)
{
	int		i;
	size_t	z;
	char	*tmp;

	i = -1;
	while (++i < counter)
	{
		tmp = get_str(s, c);
		if (!tmp)
			return (NULL);
		my_array[i] = (char *)malloc(sizeof(char) * (ft_strlen(tmp) + 1));
		if (!my_array[i])
			return (free(tmp), NULL);
		z = -1;
		while (++z < ft_strlen(tmp))
			my_array[i][z] = tmp[z];
		my_array[i][z] = '\0';
		if (!(i == counter - 1))
			s += save_2_lines((char *)s, c, tmp);
		free(tmp);
	}
	my_array[i] = NULL;
	return (my_array);
}

static char	*get_str(char const *s, char c)
{
	char	*tmp;
	char	*str;
	int		len;
	int		i;

	while (*s == c)
		s++;
	tmp = ft_strchr(s, c);
	if (!tmp)
		len = ft_strlen(s);
	else
		len = tmp - s;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = *s++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
