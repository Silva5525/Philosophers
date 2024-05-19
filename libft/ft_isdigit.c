/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:12:44 by wdegraf           #+#    #+#             */
/*   Updated: 2024/05/17 19:32:45 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief checks if d is an digital char.
/// @param d char representet with an int
/// @return (1) if true (0) if wrong
int	ft_isdigit(char d)
{
	if (d >= '0' && d <= '9')
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	d = ' ';
// 	int	out = ft_isdigit(d);

// 	printf("%i", out);
// 	return (0);
// }
