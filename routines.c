/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:08:55 by wdegraf           #+#    #+#             */
/*   Updated: 2024/06/14 15:05:17 by wdegraf          ###   ########.fr       */
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
	// pthread_mutex_lock(&philo->table->forks[philo->r_hand]);
	printf("%lld Philosopher %d has taken the right fork\n", time_stamp(philo->table->table_time), philo->id);
	// pthread_mutex_lock(&philo->table->forks[philo->l_hand]);
	// printf("%lld Philosopher %d has taken the left fork\n", time_stamp(philo), philo->id);
	// printf("%lld Philosopher %d is eating\n", time_stamp(philo), philo->id);
	// pthread_mutex_unlock(&philo->table->forks[philo->l_hand]);
	// pthread_mutex_unlock(&philo->table->forks[philo->r_hand]);
	return (NULL);
}
