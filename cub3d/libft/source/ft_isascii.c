/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:22:32 by gkonstan          #+#    #+#             */
/*   Updated: 2023/08/19 14:45:08 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*The isascii() function checks whether 
a character is ascii character (0-127) or not.*/

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
