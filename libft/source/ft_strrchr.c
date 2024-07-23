/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkonstan <gkonstan@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:22:31 by gkonstan          #+#    #+#             */
/*   Updated: 2023/08/19 14:45:08 by gkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*Returns a pointer to the last occurrence of character in the C string str.
  The terminating null-character is considered part of the C string. Therefore, 
  it can also be located to retrieve a pointer to the end of a string.*/

char	*ft_strrchr(const	char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = 0;
	while (s[i] != '\0')
		i++;
	if (!c)
		return ((char *) s + i);
	while (i >= 0)
	{
		if (s[i] == (const char) c)
			return ((char *) s + i);
		i--;
	}
	return (ptr);
}

/*int main (void)
{
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;

   ret = strrchr(str, ch);

   printf("strString after |%c| is - |%s|\n", ch, ret);
   
   return(0);
}*/
