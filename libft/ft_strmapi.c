/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:11:08 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/14 12:15:03 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/// @brief Applies the function ’f’ to each character of the
/// string ’s’, and passing its index as first argument
/// to create a new string (with malloc(3)) resulting
/// from successive applications of ’f’.
/// @param s String on which to iterate
/// @param f function to apply to each char
/// @return string created from successive appölications of f or null if fail
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*out;

	i = 0;
	len = 0;
	if (!s || !f)
		return (NULL);
	while (s[len] != '\0')
		len++;
	out = (char *)malloc(len + 1);
	if (!out)
		return (NULL);
	while (i < len)
	{
		out[i] = f(i, s[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}

// #include <stdio.h>

// char	my_stuff(unsigned int index, char c)
// {
// 	if (c >= 'a' && c <= 'z')
// 		return (c - 'a' + 'A');
// 	return (c);
// }

// int main(void)
// {
// 	char	str[] = "I`ll be back.";
// 	char	*out = ft_strmapi(str, my_stuff);

// 	if (out)
// 	{
// 		printf("Result: %s\n", out);
// 		free(out);
// 	}
// 	return (0);
// }
