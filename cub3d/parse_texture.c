/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan  < gkonstan@student.42vienn>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 01:00:00 by gkonstan          #+#    #+#             */
/*   Updated: 2024/02/03 14:28:57 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_go_and_save(t_create *create, char *path)
{
	if (ft_strncmp(create->garbage.split[0], "NO", 2) == 0)
	{
		ft_save_to_no(create, path);
		return (1);
	}
	else if (ft_strncmp(create->garbage.split[0], "SO", 2) == 0)
	{
		ft_save_to_so(create, path);
		return (1);
	}
	else if (ft_strncmp(create->garbage.split[0], "WE", 2) == 0)
	{
		ft_save_to_we(create, path);
		return (1);
	}
	else if (ft_strncmp(create->garbage.split[0], "EA", 2) == 0)
	{
		ft_save_to_ea(create, path);
		return (1);
	}
	return (0);
}

int	check_split(t_create *create)
{
	int	split_len;

	if (create->garbage.split == NULL || create->garbage.split[0] == NULL
		|| create->garbage.split[1] == NULL
		|| ft_strlen(create->garbage.split[0]) > 2)
		ft_free_exit(create, 1, "Error\nInvalid file format");
	split_len = ft_strlen(create->garbage.split[1]);
	if (create->garbage.split[1][split_len - 1] == '\n')
		create->garbage.split[1][split_len - 1] = '\0';
	if (HIDDEN == 1 && ft_hidden(create->garbage.split[1]))
		ft_free_exit(create, 1, "Error\nTexture is hidden file");
	else if (HIDDEN == 0)
	{
		if (ft_check_for_lenght(create->garbage.split[1]))
			ft_free_exit(create, 1, "Error\nInvalid texture");
	}
	return (1);
}

void	parse_texture(t_create *create)
{
	char	*path;

	if (create->garbage.split != NULL)
		ft_free_strarray(create->garbage.split);
	create->garbage.split = ft_split(create->garbage.line, ' ');
	check_split(create);
	path = ft_strdup(create->garbage.split[1]);
	if (path == NULL)
		ft_free_exit(create, 1, "Error\nMalloc failed");
	if (test_path(path) == 0)
	{
		free(path);
		ft_free_exit(create, 1, "Error\nInvalid texture path");
	}
	if (!ft_go_and_save(create, path))
	{
		free(path);
		ft_free_exit(create, 1, "Error\nInvalid file format");
	}
	free(path);
}
