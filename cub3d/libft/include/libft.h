/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:22:33 by gkonstan          #+#    #+#             */
/*   Updated: 2023/08/19 14:45:10 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>
# include <unistd.h>

typedef struct s_list
{
	struct s_list	*ptr;
	int				index;
	int				nb;
}					t_list;

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				*ft_bzero(void *s, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_calloc(size_t __nmemb, size_t __size);
int					ft_memcmp(const char *str1, const char *str2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
long int			ft_atoi(const char *str);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dest, const char *src, unsigned int size);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);

/*------------------PRINTF---------*/
int					ft_printf(const char *str, ...);
int					ft_print_string(char *arg_str);
int					ft_putchar(char c);
int					ft_print_dig(long long int nbr);
int					ft_print_uint(unsigned long nbr);
int					ft_print_vp(unsigned long long nbr);
int					ft_print_hex(unsigned long int nbr, char bos);

/*----------------GNL--------------*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char				*ft_strjoin2(char *s1, char *s2);
char				*ft_strchr2(char *s, int c);
size_t				ft_strlen2(const char *s);
char				*ft_save_line(char *temp, int fd);
char				*ft_get_first_line(char *temp);
char				*ft_rem_first_line(char *temp);
char				*get_next_line(int fd);

#endif
