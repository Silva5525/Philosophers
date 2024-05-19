/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:26:45 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/14 12:12:16 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

/// @brief The  memcmp()  function compares the first n bytes (each interpreted
/// as unsigned char) of the memory areas s1 and s2.
/// @param s1 the to compare string 1
/// @param s2 the to compare string 2
/// @param n how far to compare
/// @return negativ s1 bigger || postiv s2 bigger || if0 returns value == zero
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*c1;
	const unsigned char		*c2;
	size_t					c;

	c1 = (const unsigned char *) s1;
	c2 = (const unsigned char *) s2;
	c = 0;
	while (c < n)
	{
		if (c1[c] != c2[c])
		{
			return (c1[c] - c2[c]);
		}
		c++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char* s1 = "Alles meine Entchen";
// 	char* s2 = "Alles meine Entchen";
// 	unsigned int n = 4;
// 	int result = ft_memcmp(s1, s2, n);	
// 	printf("positiv s1 negativ s2: %i\n", result);
// 	printf("test +s1 vs -s2:%d\n", ft_memcmp(s1, s2, n));
// 	return 0;
// }