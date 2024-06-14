/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:05:07 by wdegraf           #+#    #+#             */
/*   Updated: 2024/06/14 13:51:01 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/// @brief This atoi version is based on ssize_t and returns 0, 
/// if the value does not fit into the INT_MAX or INT_MIN.
/// The point of this is that in case of an error for example 
/// if the funktion which recives the number is unsigned it does 
/// not become the highest num.. (ssize_t so i can easily reuse it)
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

/// @brief checks if d is an digital char.
/// @param d char representet with an int
/// @return (1) if true (0) if wrong
int	ft_isdigit(char *d)
{
	while (*d++)
		if (!(*d >= '0' && *d <= '9'))
			return (0);
	return (1);
}

/// @brief  uses gettimeofday to get the actual time in miliseconds.
/// Which means how many miliseconds have passed since start of 1970.
/// @param clock struct timeval for holding the actual time.
/// @return miliseconds passed since 1970.
size_t mili_count(void)
{
	struct timeval	clock;
	size_t			miliseconds;
	
	gettimeofday(&clock, NULL);
	miliseconds = (clock.tv_usec / 1000) + (clock.tv_sec * 1000);
	return (miliseconds);
}

void	free_destroy(t_p *philo)
{
	int i;

	i = 0;
	while (i < philo->table->number_of_philosophers)
	{
		pthread_mutex_destroy(&philo->table->forks[i]);
		i++;
	}
	free(philo->table->forks);
	free(philo);
}