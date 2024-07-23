SRCS = main.c \
		parse_texture_utils.c \
		parsing_utils.c \
    	window.c \
    	hook_functions.c \
    	error_handling.c \
    	parsing.c \
		check_map.c \
		ft_get_txt_info.c \
		parse_texture.c \
		parse_color.c \
		save_map.c \
		window_utils1.c \
		ray_cast.c \
		ft_free_exit.c \
		save_map_utils.c \
		main_utils.c \
		reverse_map.c \

LIBFT_NAME = ./libft/source/libft.a
MINILIBX_NAME = ./minilibx-linux/libmlx_Linux.a
OBJ_DIR = ./OBJ
NAME = cub3D
OPTION = -o
LIBFT = libft.a
CC = cc
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
CFLAGS = -Werror -Wextra -Wall -g -ggdb
LFLAGS = -L./minilibx-linux -L/usr/lib/x86_64-linux-gnu -lmlx -lXext -lX11 -lm
HIDDENFLAG = -DHIDDEN=0


all: $(LIBFT_NAME)  $(NAME)

$(NAME): $(OBJ) $(LIBFT_NAME) 
	$(CC) $(OPTION) $(NAME) $(OBJ) $(LFLAGS)  $(LIBFT_NAME)


ignore_hidden: CFLAGS += $(HIDDENFLAG)
ignore_hidden: $(LIBFT_NAME) $(NAME)

$(LIBFT_NAME):
	$(MAKE) all -C ./libft/source

$(OBJ_DIR)/%.o: %.c
	@test -d $(dir $@) || mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

test: all
	./cube3D ./maps/small.cub

clean:
	$(MAKE) clean -C ./libft/source/
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C ./libft/source/
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re