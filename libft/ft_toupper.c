/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:06:24 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/09 18:16:31 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief from lowercase to uppercase
/// @param c char to upper as int
/// @return upper case char
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c -= 32;
		return (c);
	}
	return (c);
}

// #include <stdio.h>
// int main(void)
// {
// 	char c;
// 	char res;
// 	c = 'a';
//     res = ft_toupper((unsigned char) c);
// 	printf("%c", res);
// 	return (0);
// }