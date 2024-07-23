/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:54:59 by gkonstan          #+#    #+#             */
/*   Updated: 2023/08/19 14:40:16 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	*ft_read_rest_str(int fd, char *rest_str)
{
	char	*buf;
	char	*prev_rest_str;
	int		rd_bytes;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	rd_bytes = 1;
	while (rest_str && !ft_strchr(rest_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buf, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buf);
			free(rest_str);
			return (NULL);
		}
		buf[rd_bytes] = '\0';
		prev_rest_str = rest_str;
		rest_str = ft_strjoin(rest_str, buf);
		free(prev_rest_str);
	}
	free(buf);
	return (rest_str);
}

static char	*ft_get_line(char *rest_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!rest_str[i])
		return (NULL);
	while (rest_str[i] && rest_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (rest_str[i] && rest_str[i] != '\n')
	{
		str[i] = rest_str[i];
		i++;
	}
	if (rest_str[i] == '\n')
	{
		str[i] = rest_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_new_rest_str(char *rest_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (rest_str[i] && rest_str[i] != '\n')
		i++;
	if (!rest_str[i])
	{
		free(rest_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(rest_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (rest_str[i])
		str[j++] = rest_str[i++];
	str[j] = '\0';
	if (rest_str)
		free(rest_str);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest_str = NULL;

	if (rest_str == NULL)
		rest_str = ft_strdup("");
	if (rest_str == NULL)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (rest_str)
			free(rest_str);
		return (NULL);
	}
	rest_str = ft_read_rest_str(fd, rest_str);
	if (!rest_str)
		return (NULL);
	line = ft_get_line(rest_str);
	rest_str = ft_new_rest_str(rest_str);
	return (line);
}

/*
int main(void)
{
	int			fd;
	const char	*filename;
	char		*dst;

	filename = "test.txt";
	fd = open(filename, O_RDONLY);
	printf("fd: %d\n", fd);
	dst = get_next_line(fd);
	printf("dst: %s\n", dst);
	return (0);
}*/
