/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:46:17 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/09 18:14:09 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/// @brief Allocates (with malloc(3)) and returns a substring
/// from the string ’s’. The substring begins at index ’start’ and is of
/// maximum size ’len’.
/// @param s string from which to create the substring
/// @param start index of the substring in string s
/// @param len max length of the substring
/// @return The substring. Null if fails.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	i;

	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	a = (char *)malloc(len + 1);
	if (a == NULL )
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		a[i] = s[start + i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char const		s1[] = "Alle meine Daten";
// 	unsigned int	start = 4;
// 	size_t 			len = 5;
// 	char const		*s2 = ft_substr(s1, start, len);

// 	printf("%s\n", s2);
// 	free ((void *)s2);
// 	return (0);
// }
