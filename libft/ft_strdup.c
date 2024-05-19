/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:55:13 by wdegraf           #+#    #+#             */
/*   Updated: 2024/02/20 20:45:01 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/// @brief The  strdup() function returns a pointer to a new string which is a 
/// du plicate of the string s.  Memory for the new string  is  obtained  with
/// malloc(3), and can be freed with free(3).
/// @param s1 string to duplicate
/// @return a pointer to duplicated string. Null if memory was insufficient. 
char	*ft_strdup(const char *s1)
{
	char	*a;
	size_t	l;
	size_t	i;

	i = 0;
	l = ft_strlen(s1) - 1;
	a = (char *)malloc((l + 1) * sizeof(char));
	if (!a)
		return (NULL);
	while (l != 0)
	{
		a[i] = s1[i];
		i++;
		l--;
	}
	a[i] = '\0';
	return (a);
}

// #include <stdio.h>
// int	main(void)
// {
// 	const char	s1[] = "I am dislocated Memory.";
// 	const char	*s2 = ft_strdup(s1);
// 		printf("%s\n", s2);
// 	free((void *)s2);
// 	return (0);
// }
