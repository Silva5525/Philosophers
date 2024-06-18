/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:08:55 by wdegraf           #+#    #+#             */
/*   Updated: 2024/06/18 17:10:54 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/// @brief this funktion is a more precise way of usleep. It takes the parameter
/// philo and the time in ms. It then waits until the time has passed.
/// if someone died it breaks the loop.
/// @param philo struct of the philosopher and the table.
/// @param time the time in ms the philosopher has to wait. 
void	usleep_wile_eat_sleep(t_p *philo, long long time)
{
	long long	start;
	long long	end;

	start = time_stamp(philo->table->table_time);
	end = start;
	while (end - start < time)
	{
		if (philo->table->someoene_death == true)
			break ;
		usleep(100);
		end = time_stamp(philo->table->table_time);
	}
}

static void eat_sleep_repeat(t_p *philo)
{
	if (philo->table->number_of_philosophers >= 2)
		{
			pthread_mutex_lock(&philo->table->forks[philo->l_hand]);
			safe_print(philo, "has taken the left fork\n");
			safe_print(philo, "is eating.\n");
			usleep_wile_eat_sleep(philo, philo->table->time_to_eat);
			philo->count_eat++;
			philo->time_eaten = mili_count();
			pthread_mutex_unlock(&philo->table->forks[philo->l_hand]);
		}
		pthread_mutex_unlock(&philo->table->forks[philo->r_hand]);
		safe_print(philo, "is sleeping\n");
		usleep(philo->table->time_to_sleep * 1000);
}

/// @brief 
/// @param link the void pointer to the t_p philo
/// @return 
void	*be_alive(void *link)
{
	t_p		*philo;

	philo = (t_p *)link;
	// printf("Initialized philosopher %d\n", philo->id + 1);
	if (philo->id % 2 == 0)
		usleep(philo->table->time_to_eat);
	while (philo->table->times_has_to_eat != -42 && !(philo->count_eat
			== philo->table->times_has_to_eat)
			&& philo->table->someoene_death == false)
	{
		pthread_mutex_lock(&philo->table->forks[philo->r_hand]);
		safe_print(philo, "has taken the right fork\n");
		eat_sleep_repeat(philo);
		safe_print(philo, "is thinking\n");
	}
	return (NULL);
}
