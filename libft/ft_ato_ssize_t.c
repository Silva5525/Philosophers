/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ato_ssize_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:27:17 by wdegraf           #+#    #+#             */
/*   Updated: 2024/05/17 22:59:35 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/// @brief The atoi() function converts the initial portion of the string 
/// pointed to by str to int representation
/// @param str the initial portion
/// @return the int representation
ssize_t	ft_ato_ssize_t(const char *str)
{
	ssize_t	hold;
	ssize_t	reverse;

	hold = 0;
	reverse = 1;
	while ((*str == '\t') || (*str == '\n') || (*str == '\v')
		|| (*str == '\f') || (*str == '\r') || (*str == ' '))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			reverse = -1;
		str++;
		if (*str == '-' || *str == '+')
			return (0);
	}
	while (*str >= '0' && *str <= '9')
	{
		hold = ((*str - '0') + (hold * 10));
		str++;
	}
	if (*str != '\0' && (*str <= '0' && *str >= '9'))
		return (0);
	return (hold * reverse);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	str[] = "+-54";
// 	int out = ft_atoi(str);
// 	printf("%d\n", out);
// 	return (0);
// }
