/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:51:47 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/14 12:35:57 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief The  memmove()  function  copies n bytes from memory area src to 
/// memory area dest. The memory areas may overlap: copying takes place as 
/// though the  bytes in src are first copied into a temporary array that does
/// not overlap src or dest, and the bytes are then copied from the temporary
/// array to dest.
/// @param dst destination for new string
/// @param src string to copy
/// @param len how long to copy
/// @return 
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*dst2;
	const unsigned char		*src2;

	if (dst == 0 && src == 0)
		return (NULL);
	dst2 = (unsigned char *)dst;
	src2 = (const unsigned char *)src;
	if (src2 < dst2 && src2 + len > dst2)
	{
		dst2 += len;
		src2 += len;
		while (len > 0)
		{
			dst2--;
			src2--;
			*dst2 = *src2;
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst2);
}

// #include <stdio.h>
// test a:
// int	main(void)
// {
// 	char	str[] = "abcdefghijklmnopqrstuvwxyz";
// 	char	dest[27];

// 	ft_memmove(dest, str+8, sizeof(char) * 4);
// 	printf("dest: %s\n", dest);
// 	return (0);
// }

// test b:
// int main()
// {
// 	char str1[7] = "abcdef";
//    printf("\nstr1: %s\n", str1);
//    printf( "The string: %s\n", str1 );
//    ft_memmove( (str1+6), str1, 10 );
//    printf( "New string: %s\n", str1 );
// }
