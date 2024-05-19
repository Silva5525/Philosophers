/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:00:58 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/14 12:14:33 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/// @brief The strlcat() function appends the NUL-terminated string src to the 
/// end of dst.  It will append at most size - strlen(dst) - 1 bytes, NUL-termi‐
/// nating the result.
/// @param dst will be appendet 
/// @param src appends to the end of dst
/// @param dstsize most size of which it can be append
/// @return the total length of the string that would have been created if there
/// were enough space in the destination buffer.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (src[i] && (dst_len + i) < dstsize - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// #include <stdio.h>
// 	int	main(void)
// {
// 	char	dst[50] = "What should i do? ";
// 	char	src[] = "Use a Towel!";
// 	ft_strlcat(dst, src, strlen(dst));
// 	printf("Formatted: %s\n", dst);
// 	return (0);
// }
