/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:38:16 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/14 12:16:18 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief The strrchr() function returns a pointer to the last occurrence of 
/// the character c in the string s.
/// @param s string to iterate
/// @param c searched character in s
/// @return a pointer to the last occurence of c
char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	us;

	i = ft_strlen(s);
	us = (unsigned char)c;
	while (i >= 0)
	{
		if (s[i] == us)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char s[] = "Wo ist Waldi;";
// 	char c = 'i';
// 	char *out = ft_strrchr(s, c);
// 	if (out != NULL)
// 		printf("Found last '%c' at position %ld.\n", c, out - s);
// 	else
// 		printf ("'%c' not found in this String.\n", c);
// 	return (0);
// }
