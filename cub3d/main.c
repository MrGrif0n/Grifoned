/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:52:03 by ngjokaj           #+#    #+#             */
/*   Updated: 2024/02/02 20:35:06 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	main(int argc, char **argv)
{
	t_create	*create;

	create = ft_calloc(1, sizeof(t_create));
	if (!create)
		handle_error("Error\nMemory allocation failed");
	if (argc != 2)
		ft_free_exit(create, 1, "Error\nUsage: ./cub3D <map.cub>");
	if (HIDDEN != 1 && HIDDEN != 0)
		ft_free_exit(create, 1, "Error\nHIDDEN macro is not set or invalid");
	if (check_extension(create, argv[1], ".cub"))
		ft_free_exit(create, 1, "Error\nInvalid file");
	init_structs(create);
	parse_argv(argv[1], create);
	if (!create->map_info.map)
		ft_free_exit(create, 1, "Error\nMap is not initialized");
	if (!check_all_info_initialized(create))
		ft_free_exit(create, 1, "Error\nInvalid file format");
	if (!check_map(create))
		ft_free_exit(create, 1, "Error\nMap is not valid");
	reverse_map_x(create);
	if (initialize_window(create) != 0)
		ft_free_exit(create, 1, "Error\nInitialisation error");
	return (0);
}
