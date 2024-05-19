/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:51:29 by wdegraf           #+#    #+#             */
/*   Updated: 2024/02/20 19:24:08 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief The  strchr() function returns a pointer to the first occurrence of 
/// the character c in the string s.
/// @param s Through searched string
/// @param c char which is searched
/// @return pointer to the first occurrence of c 
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char s[] = "Wo ist Waldi;";
// 	char c = 'y';
// 	char *out = ft_strchr(s, c);
// 	if (out != NULL)
// 		printf("Found '%c' at position %ld.\n", c, out - s);
// 	else
// 		printf ("'%c' not found in this String.\n", c);
// 	return (0);
// }
