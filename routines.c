/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:08:55 by wdegraf           #+#    #+#             */
/*   Updated: 2024/06/16 17:42:43 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/// @brief 
/// @param link the void pointer to the t_p philo
/// @return 
void	*be_alive(void *link)
{
	t_p		*philo;

	philo = (t_p *)link;
	bool print = true;
	while (print)
	{
		pthread_mutex_lock(&philo->table->print_mutex);
		printf("Philosopher %d is alive\n", philo->id + 1);
		print = false;
		pthread_mutex_unlock(&philo->table->print_mutex);
	}
	// printf("Initialized philosopher %d\n", philo->id + 1);
	// if (philo->id % 2 == 0)
	// 	usleep(philo->id * 300);
	/// check how to loop the eat sleep think after the usleepfunktion
	/// check if the philo is dead comes later 
	/// think about a better way to hakdle which philo starts first.
	// pthread_mutex_lock(&philo->table->forks[philo->r_hand]);
	safe_print(philo, "has taken the right fork\n");
	// pthread_mutex_lock(&philo->table->forks[philo->l_hand]);
	// printf("%lld Philosopher %d has taken the left fork\n", time_stamp(philo), philo->id);
	// printf("%lld Philosopher %d is eating\n", time_stamp(philo), philo->id);
	// pthread_mutex_unlock(&philo->table->forks[philo->l_hand]);
	// pthread_mutex_unlock(&philo->table->forks[philo->r_hand]);
	return (NULL);
}
