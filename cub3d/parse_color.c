/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan  < gkonstan@student.42vienn>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:16:33 by gkonstan          #+#    #+#             */
/*   Updated: 2024/02/03 14:46:03 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "libft/include/libft.h"

static int	ft_check_rgb(int r, int g, int b)
{
	if (r < 0 || r > 255)
		return (1);
	if (g < 0 || g > 255)
		return (1);
	if (b < 0 || b > 255)
		return (1);
	return (0);
}

static int	ft_check_num(int r, int g, int b, char **rgb)
{
	char	*str;
	int		flag;

	str = ft_itoa(r);
	flag = 0;
	if (ft_strncmp(rgb[0], str, ft_strlen(rgb[0])) != 0)
		flag = 1;
	free(str);
	str = ft_itoa(g);
	if (ft_strncmp(rgb[1], str, ft_strlen(rgb[1])) != 0)
		flag = 1;
	free(str);
	str = ft_itoa(b);
	if (ft_strncmp(rgb[2], str, ft_strlen(rgb[2])) != 0)
		flag = 1;
	free(str);
	if (ft_check_rgb(r, g, b))
		flag = 1;
	return (flag);
}

static int	save_color_to_struct(int *i_rgb, char identifier, t_create *create)
{
	if (identifier == 'F' && create->colors.floor == -1)
	{
		create->colors.floor = (i_rgb[0] << 16) | (i_rgb[1] << 8) | i_rgb[2];
		return (1);
	}
	else if (identifier == 'C' && create->colors.ceiling == -1)
	{
		create->colors.ceiling = (i_rgb[0] << 16) | (i_rgb[1] << 8) | i_rgb[2];
		return (1);
	}
	return (0);
}

void	ft_free_two_strarray(char **str1, char **str2, t_create *create, int f)
{
	ft_free_strarray(str1);
	ft_free_strarray(str2);
	if (f)
		ft_free_exit(create, 1, "Error\nInvalid file format");
}

void	parse_color(t_create *create, char **split)
{
	char	identifier;
	int		i_rgb[3];
	char	**c_rgb;

	create->garbage.line[ft_strlen(create->garbage.line) - 1] = '\0';
	split = ft_split(create->garbage.line, ' ');
	if (!split || !split[0] || !split[1] || split[2])
	{
		if (split)
			ft_free_strarray(split);
		ft_free_exit(create, 1, "Error\nInvalid color format or malloc fail");
	}
	c_rgb = ft_split(split[1], ',');
	if (!c_rgb || !c_rgb[0] || !c_rgb[1] || !c_rgb[2] || c_rgb[3])
		ft_free_two_strarray(split, c_rgb, create, 1);
	identifier = split[0][0];
	i_rgb[0] = ft_atoi(c_rgb[0]);
	i_rgb[1] = ft_atoi(c_rgb[1]);
	i_rgb[2] = ft_atoi(c_rgb[2]);
	if (ft_check_num(i_rgb[0], i_rgb[1], i_rgb[2], c_rgb))
		ft_free_two_strarray(split, c_rgb, create, 1);
	if (!save_color_to_struct(i_rgb, identifier, create))
		ft_free_two_strarray(split, c_rgb, create, 1);
	ft_free_two_strarray(split, c_rgb, create, 0);
}
