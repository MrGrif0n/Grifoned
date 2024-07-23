/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:22:31 by gkonstan          #+#    #+#             */
/*   Updated: 2023/08/19 14:45:07 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_check_next_letter(char str, va_list arg);

int	ft_printf(const char *str, ...)
{
	va_list			arg;
	unsigned int	i;
	unsigned int	j;
	unsigned int	check;

	va_start(arg, str);
	i = 0;
	check = 0;
	while (*str)
	{
		if (*str == '%')
		{
			j = i;
			i += ft_check_next_letter(*++str, arg);
			if (++j > i && *str != 's')
				check = 1;
		}
		else
			i += ft_putchar(*str);
		str++;
	}
	va_end(arg);
	if (check)
		return (-1);
	return (i);
}

static int	ft_check_next_letter(char str, va_list arg)
{
	char	c;

	if (str == '%')
		return (write(1, "%", 1));
	if (str == 'c')
	{
		c = va_arg(arg, int);
		return (write(1, &c, 1));
	}
	if (str == 's')
		return (ft_print_string(va_arg(arg, char *)));
	if (str == 'p')
		return (ft_print_vp(va_arg(arg, unsigned long long)));
	if (str == 'd' || str == 'i')
		return (ft_print_dig(va_arg(arg, int)));
	if (str == 'u')
		return (ft_print_uint(va_arg(arg, unsigned int)));
	if (str == 'x' || str == 'X')
		return (ft_print_hex(va_arg(arg, unsigned int), str));
	else
		return (0);
}

//int main(void)
//{
//
//		
//	int	i1 = 2147483647;
//	int	i2 = 2147483647;
//	int	i3 = -42967295;
//	char str[] = "lemts go:      ";
//	ft_printf(" %i \n", ft_printf("f %s %% %d %i %u", str, i1, i2, i3));
//	ft_printf("%u\n", 9223372036854775807LL);
//	ft_printf("%u\n", ULONG_MAX);
//	ft_printf(" %i\n", ft_printf("this is str before %h this is after"));
//	ft_printf(" %i\n", ft_printf("this is str before %h"));
//	ft_printf(" %i\n", ft_printf("this is str before %h\n"));
//	ft_printf(" %i\n", ft_printf("15: %x", -15));
//	ft_printf("\n");
//	printf("%i", printf("%x", -9));
//	
//}
