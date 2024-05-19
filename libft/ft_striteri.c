/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:03:35 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/09 17:32:00 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/// @brief Applies the function ’f’ on each character of
/// the string passed as argument, passing its index
/// as first argument. Each character is passed by
/// address to ’f’ to be modified if necessary.
/// @param s String on which to iterate
/// @param f function to apply to each character of s
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}

// #include <stdio.h>

// void	my_stuff(unsigned int i, char *c)
// {
// 	if (i % 2 == 0)
// 		*c = ft_toupper(*c);
// }

// int	main(void)
// {
// 	char	str[] = "Yo no hablo espanol.";

// 	printf("Original = %s\n", str);
// 	ft_striteri(str, my_stuff);
// 	printf("Mod = %s\n", str);
// 	return (0);
// }