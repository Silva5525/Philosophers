/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:10:11 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/14 12:13:37 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/// @brief The  memset()  function  fills  the  first  n  bytes of the memory 
/// area pointed to by s with the constant byte c.
/// @param s string which to be filled
/// @param c with what to fill 
/// @param n how many bytes to fill
/// @return pointer to the memory area s
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	bvalue;

	ptr = (unsigned char *)b;
	bvalue = (unsigned char)c;
	while (0 < len)
	{
		*ptr = bvalue;
		ptr++;
		len--;
	}
	return (b);
}

// #include <stdio.h>
// int main(void)
// {
// 	char	str[40];
// 	int	value = 4;
// 	size_t	i = 0;
// 	size_t	len = sizeof(str);

// 	ft_memset(str, value, len);
// 	while (i < len)
// 	{
// 		printf("str[%zu] = %u\n", i, str[i]);
// 		i++;
// 	}
// 	return (0);
// }
