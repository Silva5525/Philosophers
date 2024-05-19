/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:58:47 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/14 12:16:09 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

/// @brief searched first occurrence of needle in haystack but looks not more 
/// then len chars are searched. Chars that appear after \0 char are not searchd
/// @param haystack string to iterate
/// @param needle to find string
/// @param len max chars to look at
/// @return if needl is NULL = haystack || if needle occurs nowhere NULL ||
/// or a pointer to the first char of the first occurance of needle returned
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*hay2;
	const char	*n2;
	size_t		i;

	n2 = needle;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len)
	{
		hay2 = haystack;
		i = len;
		while (*haystack == *needle && 0 < len
			&& *haystack != '\0' && *(needle++) != '\0')
		{
			haystack++;
			len--;
		}
		if (*needle == '\0')
			return ((char *)hay2);
		haystack = hay2 + 1;
		len = i - 1;
		needle = n2;
	}
	return (NULL);
}

// int	main(void)
// {
// // // // // // 	char		*hay = "Alles meine endchen des endes";
// // // // // // 	char		*needle = "end";
// // // // // // 	size_t		len = 12;
// // // // // // 	printf("%s\n", strnstr(hay, needle, len));
// // // // // // 	const char	*show = ft_strnstr(hay, needle, len);
// // // // // // 	printf("show: %s\n", show);
// char haystack[30] = "aaabcabcd";
// printf("%i\n", ft_strnstr(haystack, "abcd", 9) == haystack + 6);
// printf("%s\n", ft_strnstr(haystack, "abcd", 9));
// return (0);
// }
