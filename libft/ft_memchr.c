/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:26:35 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/09 16:25:33 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/// @brief The  memchr()  function  scans  the  initial n bytes of the memory
/// area pointed to by s for the first instance of c.  Both c and the  bytes  of
/// the memory area pointed to by s are interpreted as unsigned char.
/// @param s area which need to be scaned
/// @param c to find char
/// @param n max bytes to be scaned
/// @return a pointer to the matching byte or null if not found
void	*ft_memchr(const void *s, int c, size_t n)
{
	int						i;
	const unsigned char		*s1;

	s1 = (const unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		if (s1[i] == (unsigned char)c)
			return ((void *)(s1 + i));
		i++;
		n--;
	}
	return (NULL);
}

// #include <stdio.h>
// int	main(void)
// {
// 	const char	*str = "bonjourno";
// 	char		sC = 'n';
// 	const char	*out = ft_memchr(str, sC, 2);
// 	if (out != NULL)
// 		printf("memchr: Found '%c' at positigon %ld\n", sC, out - str);
// 	else
// 		printf ("'%c' not found in this String.\n", sC);
// 	return (0);
// }
