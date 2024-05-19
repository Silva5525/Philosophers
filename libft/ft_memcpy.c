/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:30:38 by wdegraf           #+#    #+#             */
/*   Updated: 2024/02/20 19:45:41 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief The  memcpy()  function  copies  n bytes from memory area src to
/// memory area dest.  The memory areas must not overlap.  Use memmove(3)  
/// if  the memory areas do overlap.
/// @param dst destination for new string
/// @param src string which to copy
/// @param len how long to copy
/// @return a pointer to dest
void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char		*dst2;
	const unsigned char	*src2;

	if (dst == 0 && src == 0)
		return (NULL);
	dst2 = (unsigned char *) dst;
	src2 = (const unsigned char *) src;
	while (len > 0)
	{
		*dst2 = *src2;
		src2++;
		dst2++;
		len--;
	}
	return (dst);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	str[] = "abcdefghijklmnopqrstuvwxyz";
// 	char	dest[27];
// 	ft_memcpy(dest, str+8, sizeof(char) * 4);
// 	printf("dest: %s\n", dest);
// 	return (0);
// }

// int main()
// {
// 	char str1[7] = "abcdef";
//    printf( "The string: %s\n", str1 );
//    ft_memcpy( (str1+6), str1, 10 );
//    printf( "New string: %s\n", str1 );
// }
