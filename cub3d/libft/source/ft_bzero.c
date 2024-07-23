/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:22:31 by gkonstan          #+#    #+#             */
/*   Updated: 2023/08/19 14:45:07 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*The bzero() function erases the data in the n bytes of the memory
  starting at the location pointed to by s, by writing zeros (bytes
  containing '\0') to that area.*/

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*biff;

	biff = s;
	while (n > 0)
	{
		*biff = '\0';
		biff++;
		n--;
	}
	return (s);
}
