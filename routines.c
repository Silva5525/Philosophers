/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:08:55 by wdegraf           #+#    #+#             */
/*   Updated: 2024/06/17 12:06:09 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/// @brief 
/// @param link the void pointer to the t_p philo
/// @return 
void	*be_alive(void *link)
{
	t_p		*philo;
	bool	wait;
	bool	wait2;

	wait = true;
	wait2 = true;
	philo = (t_p *)link;
	// printf("Initialized philosopher %d\n", philo->id + 1);
	// if (philo->id % 2 != 0)
		// usleep(philo->id * 20);
	while (wait == true)
	{
		pthread_mutex_lock(&philo->table->forks[philo->r_hand]);
		safe_print(philo, "has taken the right fork\n");
		wait = false;
		while (wait2 == true)
		{
			pthread_mutex_lock(&philo->table->forks[philo->l_hand]);
			safe_print(philo, "has taken the left fork\n");
			safe_print(philo, "is eating\n");
			wait2 = false;
			// printf("%lld Philosopher %d has taken the left fork\n", time_stamp(philo), philo->id);
			// printf("%lld Philosopher %d is eating\n", time_stamp(philo), philo->id);
			pthread_mutex_unlock(&philo->table->forks[philo->l_hand]);
		}
		pthread_mutex_unlock(&philo->table->forks[philo->r_hand]);
	}
	return (NULL);
}
