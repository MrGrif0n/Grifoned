/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:42:38 by ngjokaj           #+#    #+#             */
/*   Updated: 2024/02/02 20:30:34 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	handle_error(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}
