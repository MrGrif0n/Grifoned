/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:54:08 by ngjokaj           #+#    #+#             */
/*   Updated: 2024/02/02 20:06:00 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include <stdbool.h>
# include <mlx.h>
// # include "./minilibx-linux/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include "libft/include/libft.h"
# include <stdlib.h>
# include <X11/keysym.h>
# include <math.h>
# include <unistd.h>
# define MAX_MAP_H 100
# define MAX_MAP_W 100
# define WIN_WIDTH 1080
# define WIN_HEIGHT 720
# define TILE_SIZE 64
# ifndef HIDDEN
#  define HIDDEN 1
# endif
// FOV = 120 degrees
// FOV = 2.094 radians
// FOV = 60 degrees
// FOV = 1.047 radians
// FOV = 360 degrees
// FOV = 6.283 radians
// FOV = 90 degrees
// FOV = 1.570 radians
# define FOV 1.047f
# define PLAYER_HEIGHT 32

typedef struct s_colors
{
	int	floor;
	int	ceiling;
}	t_colors;

typedef struct s_player
{
	double	x;
	double	y;
	double	x_px;
	double	y_px;
	int		first_ray;
	int		last_ray;
	float	view;
	char	direction;
}	t_player;

typedef struct s_map_info
{
	int		width;
	int		height;
	char	**map;
}	t_map_info;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		height;
	int		width;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_x_texture
{
	void	*img;
	char	*file_name;
	t_img	texture;
}	t_x_texture;

typedef struct s_garbage
{
	char	*line;
	char	**split;
}	t_garbage;

typedef struct s_create
{
	void		*mlx;
	void		*win;
	int			txt_idx;
	float		txt_w;
	int			sub;
	t_garbage	garbage;
	t_img		img;
	t_x_texture	west;
	t_x_texture	east;
	t_x_texture	north;
	t_x_texture	south;
	t_map_info	map_info;
	t_player	player;
	t_colors	colors;
}	t_create;

typedef struct s_ray
{
	int		sx;
	int		sy;
	float	dx;
	float	dy;
	float	hor_x;
	float	hor_y;
	float	vert_x;
	float	vert_y;
	float	vert_dist;
	float	hor_dist;
	float	vert_w;
	float	hor_w;
}	t_ray;

int		initialize_window(t_create *create);
int		close_window(t_create *create);
int		key_hook(int keycode, t_create *create);
int		check_map(t_create *create);
void	handle_error(const char *message);
float	ft_get_txt_height(t_create	*create);
int		ft_get_txt_width(t_create	*create);
void	*ft_get_txt_addr(t_create	*create);
int		ft_sign(float f);
void	parse_argv(const char *argv, t_create *create);
float	ft_ray(t_create	*create, float v);
void	render_loop(t_create *create);
void	ft_ray_cast(t_create *create);
void	ft_line(t_create *create, int w, float dist);
int		ft_check_for_lenght(char *file);
float	ft_ray(t_create	*create, float v);
float	ft_save_color(t_create *create, float dist, int color_idx, float w);
void	ft_ray_next_step_calculation(t_create *create, t_ray *r);
void	ft_ray_initial_calculations(t_create *create, t_ray *r, float v);
void	init_pos(t_create *create);
void	find_angle_view(t_create *create, char c);
void	init_rays_angel(t_create *create);
void	parse_texture(t_create *create);
int		ft_hidden(char *file);
void	parse_color(t_create *create, char **split);
void	save_map(const char *map_name, t_create *create);
void	print_map(t_create *create);
void	ft_get_info_map(t_create *create, int fd, char *line);
char	*skip_until_map(int fd);
int		parse_texture_and_color(t_create *create);
void	init_structs(t_create *create);
int		check_all_info_initialized(t_create *create);
int		check_extension(t_create *create, char *file, char *ext);
int		check_all_textures(t_create *create);
void	ft_free_strarray(char **strarray);
int		test_path(char *path);
void	reverse_map_x(t_create *create);
int		check_all_textures(t_create *create);
int		check_spaces_and_null(t_create *create, int i, int j);
void	ft_free_exit(t_create *create, int close, char *msg);
void	free_map(t_map_info *map_info);
int		check_xpm_extension(char *path);
void	ft_save_to_ea(t_create *create, char *path);
void	ft_save_to_we(t_create *create, char *path);
void	ft_save_to_so(t_create *create, char *path);
void	ft_save_to_no(t_create *create, char *path);
#endif
