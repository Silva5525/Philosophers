/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:05:07 by wdegraf           #+#    #+#             */
/*   Updated: 2024/06/05 18:37:11 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/// @brief This atoi version is based on ssize_t and returns 0, 
/// if the value does not fit into the INT_MAX or INT_MIN.
/// The point of this is that in case of an error for example 
/// if the funktion which recives the number is unsigned it does 
/// not become the highest num.. (ssize_t so i can easily reuse it for other functions)
/// @param str which is converted.
/// @return the converted int value. Or 0 if the value does not fit into the 
/// INT_MAX or INT_MIN.
int	ft_atoi(const char *str)
{
	ssize_t n;
	ssize_t minus;
	
	if (!str)
		return (0);
	n = 0;
	minus = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str != '\0')
		n = n * 10 + (*str++ - '0');
	n *= minus;
	if ((n > INT_MAX ) || (n < INT_MIN))
		return (0);
	return ((int)n);
}