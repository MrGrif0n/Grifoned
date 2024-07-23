/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_txt_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:31:52 by gkonstan          #+#    #+#             */
/*   Updated: 2024/02/02 20:34:43 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

float	ft_get_txt_height(t_create *create)
{
	if (create->txt_idx == 0)
		return (create->west.texture.height);
	else if (create->txt_idx == 1)
		return (create->south.texture.height);
	else if (create->txt_idx == 2)
		return (create->east.texture.height);
	else if (create->txt_idx == 3)
		return (create->north.texture.height);
	return (0);
	return (0);
}

int	ft_get_txt_width(t_create *create)
{
	if (create->txt_idx == 0)
		return (create->west.texture.width);
	else if (create->txt_idx == 1)
		return (create->south.texture.width);
	else if (create->txt_idx == 2)
		return (create->east.texture.width);
	else if (create->txt_idx == 3)
		return (create->north.texture.width);
	return (0);
}

void	*ft_get_txt_from_sub(t_create *create)
{
	if (create->txt_idx == 0)
		return (create->west.texture.addr);
	else if (create->txt_idx == 1)
		return (create->south.texture.addr);
	else if (create->txt_idx == 2)
		return (create->east.texture.addr);
	else if (create->txt_idx == 3)
		return (create->north.texture.addr);
	return (0);
}

void	*ft_get_txt_addr(t_create *create)
{
	if (create->sub)
		return (ft_get_txt_from_sub(create));
	if (create->txt_idx == 0)
		return (create->east.texture.addr);
	else if (create->txt_idx == 1)
		return (create->north.texture.addr);
	else if (create->txt_idx == 2)
		return (create->west.texture.addr);
	else if (create->txt_idx == 3)
		return (create->south.texture.addr);
	return (0);
}
