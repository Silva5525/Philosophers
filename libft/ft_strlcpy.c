/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:55:50 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/14 12:14:44 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief he strlcpy() function copies up to size - 1 characters from the
/// NUL-ter‐minated string src to dst, NUL-terminating the result.
/// @param dst copy destination
/// @param src sorce what to copy to destination 
/// @param ds size of how much to copy 
/// @return the length of src
size_t	ft_strlcpy(char *dst, const char *src, size_t ds)
{
	size_t		i;

	i = 0;
	if (ds > 0)
	{
		while (i < ds - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

// #include <stdio.h>
// int main(void)
// {
// 	char dst[29];
// 	char	src[] = "You should carry a Towel.";

// 	int chars_w = ft_strlcpy( dst, src, sizeof(dst));

// 	if (chars_w >= 0 && chars_w < sizeof(dst))
// 	{
// 		printf("Formatted string: %s\n", dst);
// 	}
// }