/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:45:31 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/14 12:15:20 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief The  strcmp() function compares the two strings s1 and s2. The locale
/// is not taken into account. The comparison is done using unsigned characters.
/// @param s1 string 1
/// @param s2 string 2
/// @param n how long to compare
/// @return 0 if equal || -1 if s1 < s2 || 1 if s1 > s2
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	c = 0;
	while ((s1[c] != '\0' || s2[c] != '\0') && c != n)
	{
		if ((unsigned char)s1[c] != (unsigned char)s2[c])
		{
			return ((int)((unsigned char)s1[c] - (unsigned char)s2[c]));
		}
		c++;
	}
	if (n == c)
		return (0);
	return (0);
}

// #include <stdio.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char* s1 = "test\200";
// 	char* s2 = "test\0";
// 	unsigned int n = 6;
// 	int result = ft_strncmp(s1, s2, n);	
// 	printf("positiv s1 negativ s2: %i\n", result);
// 	printf("test +s1 vs -s2:%d\n", strncmp(s1, s2, n));
// 	return 0;
// }