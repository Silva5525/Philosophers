/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:49:13 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/09 18:15:32 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief From uppercase to lowercase
/// @param c char to lower
/// @return the lowercase char
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c += 32;
		return (c);
	}
	return (c);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	b = 'P';
// 	b = ft_tolower(b);
// 	printf("%c\n", b);
// 	return (0);
// }
