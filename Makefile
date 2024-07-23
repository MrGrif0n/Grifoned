SRCS = main.c \
	kanami.c \
	screen.c \


LIBFT_NAME = ./libft/source/libft.a
MINILIBX_NAME = ./minilibx-linux/libmlx_Linux.a
OBJ_DIR = ./OBJ
NAME = grifoned
OPTION = -o
LIBFT = libft.a
CC = cc
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
CFLAGS = -Werror -Wextra -Wall -g -ggdb
LFLAGS = -L./minilibx-linux -L/usr/lib/x86_64-linux-gnu -lmlx -lXext -lX11 -lm



all:  $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(OPTION) $(NAME) $(OBJ) $(LFLAGS) 



$(OBJ_DIR)/%.o: %.c
	@test -d $(dir $@) || mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

test: all
	./cube3D ./maps/small.cub

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re