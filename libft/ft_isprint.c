/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:40:04 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/14 10:38:55 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief checks if a is an printable character.
/// @param a char representet as an int
/// @return 1 if true 0 if not true
int	ft_isprint(int a)
{
	if (a >= 32 && a <= 126)
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// int	main (void)
// {
// 	char	a = 31;
// 	int	out = ft_isprint(a);
// 	printf("%i", out);
// 	return (0);
// }
