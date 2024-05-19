/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:30:30 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/09 18:12:12 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/// @brief Allocates (with malloc(3)) and returns a copy of
/// ’s1’ with the characters specified in ’set’ removed
/// from the beginning and the end of the string.
/// @param s1 String to be trimmed
/// @param set reference set of characters to trim
/// @return The trimmed string. NULL if the allocation fails.
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s3;
	size_t	len;
	size_t	i1;
	size_t	i2;

	i1 = 0;
	i2 = 0;
	while (s1[i1] && ft_strchr(set, s1[i1]))
		i1++;
	len = ft_strlen(s1);
	while (len > i1 && ft_strchr(set, s1[len - 1]))
		len--;
	s3 = (char *)malloc(len - i1 + 1);
	if (s3 == NULL)
		return (NULL);
	while (len > i1)
	{
		s3[i2] = s1[i1];
		i1++;
		i2++;
	}
	s3[i2] = '\0';
	return (s3);
}

// #include <stdio.h>
// int	main(void)
// {
// char const	s1[] = "Whoo? to loooong *s.fo? to loooong *s.";
// char const	set[] = "Whoo? to loooong *s.";
// char const	*s2 = ft_strtrim(s1, set);
// printf("%s", s2);
// free((void *)s2);
// return (0);
// }
