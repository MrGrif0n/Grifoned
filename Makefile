SRCS = main.c \


LIBFT_NAME = ./libft/source/libft.a
MINILIBX_NAME = ./minilibx-linux/libmlx_Linux.a
OBJ_DIR = ./OBJ
NAME = hacked
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