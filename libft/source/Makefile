NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isascii.c ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isprint.c \
		ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
		ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_print_dig_int.c ft_print_vp.c ft_print_uint.c ft_print_x_X.c ft_printf.c ft_printf_string.c ft_putchar.c \
		ft_lstnew.c ft_lstlast.c ft_lstadd_back.c \
		get_next_line.c \


OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g
MAKEFLAGS = -j$(nproc)

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
