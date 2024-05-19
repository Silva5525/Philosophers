/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:00:04 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/14 10:36:58 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief The bzero() function writes n zeroed bytes to the string s.  
/// If n is zero, bzero() does nothing.
/// @param s the string s
/// @param n zeroed bytes
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)s;
	while (n > 0)
	{
		p[i] = 0;
		i++;
		n--;
	}
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	s[] = "abcdefg";
// 	size_t	i = 0;
// 	size_t	n = sizeof(s);

// 	ft_bzero(s, n);
// 	while (i < n)
// 	{
// 		printf("s[%zu] = %u\n", i, s[i]);
// 		i++;
// 	}

// }
