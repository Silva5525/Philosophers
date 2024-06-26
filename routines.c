/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:08:55 by wdegraf           #+#    #+#             */
/*   Updated: 2024/06/26 14:26:00 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/// @brief thread safe print function. It usleeps for 100ms each time so
/// the if statement has time to check if someone died. It then locks the
/// print_mutex and prints the string.
/// @param philo struct of the philosopher and the table.
/// @param str the string to print.
void	safe_print(t_p *philo, char *str)
{
	bool	print;

	print = true;
	usleep(100);
	if (pthread_mutex_lock(&philo->table->print_mutex),
		print == true && philo->table->someoene_death == false
		&& !(philo->count_eat == philo->table->times_has_to_eat))
	{
		pthread_mutex_unlock(&philo->table->print_mutex);
		pthread_mutex_lock(&philo->table->print_mutex3);
		printf("%lld %d %s",
			time_stamp(philo), philo->id + 1, str);
		print = true;
		pthread_mutex_unlock(&philo->table->print_mutex3);
	}
	pthread_mutex_unlock(&philo->table->print_mutex);
}

/// @brief this funktion is a more precise way of usleep. It takes the parameter
/// philo and the time in ms. It then waits until the time has passed.
/// if someone died it breaks the loop.
/// @param philo struct of the philosopher and the table.
/// @param time the time in ms the philosopher has to wait. 
void	usleep_wile_eat_sleep(t_p *philo, long long time)
{
	long long	start;
	long long	end;

	start = time_stamp(philo);
	end = start;
	while (end - start < time)
	{
		pthread_mutex_lock(&philo->table->print_mutex);
		if (philo->table->someoene_death == true)
		{
			pthread_mutex_unlock(&philo->table->print_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->table->print_mutex);
		usleep(1000);
		end = time_stamp(philo);
	}
}

/// @brief split the be_alive function into 2 parts. So the eat and sleep part
/// happens here. only interesting part is the usleep_wile_eat_sleep function.
/// so check that out.
/// @param philo struct of the philosopher and the table.
static int	eat_sleep_repeat(t_p *philo)
{
	if (philo->table->number_of_philosophers >= 2)
	{
		pthread_mutex_lock(&philo->table->forks[philo->l_hand]);
		safe_print(philo, "has taken a fork\n");
		safe_print(philo, "is eating\n");
		usleep_wile_eat_sleep(philo, philo->table->time_to_eat);
		philo->count_eat++;
		pthread_mutex_lock(&philo->table->print_mutex);
		philo->time_eaten = mili_count();
		pthread_mutex_unlock(&philo->table->print_mutex);
		pthread_mutex_unlock(&philo->table->forks[philo->l_hand]);
	}
	pthread_mutex_unlock(&philo->table->forks[philo->r_hand]);
	pthread_mutex_lock(&philo->table->print_mutex);
	if (philo->table->someoene_death == true)
		return (pthread_mutex_unlock(&philo->table->print_mutex), 0);
	pthread_mutex_unlock(&philo->table->print_mutex);
	safe_print(philo, "is sleeping\n");
	usleep_wile_eat_sleep(philo, philo->table->time_to_sleep);
	return (0);
}

/// @brief this funktion is the initial function for the threads.
/// it takes the void pointer to the t_p philo and starts the loop.
/// if the philo has an odd id it waits until the other philosophers
/// have taken their forks.
/// @param link the void pointer to the t_p philo
/// @return NULL
void	*be_alive(void *link)
{
	t_p		*philo;

	philo = (t_p *)link;
	if (philo->id % 2 == 0)
		usleep(500);
	while (pthread_mutex_lock(&philo->table->print_mutex)
		, !(philo->count_eat == philo->table->times_has_to_eat))
	{
		if (philo->table->someoene_death == true)
			return (pthread_mutex_unlock(&philo->table->print_mutex), NULL);
		pthread_mutex_unlock(&philo->table->print_mutex);
		pthread_mutex_lock(&philo->table->forks[philo->r_hand]);
		safe_print(philo, "has taken a fork\n");
		eat_sleep_repeat(philo);
		safe_print(philo, "is thinking\n");
	}
	pthread_mutex_unlock(&philo->table->print_mutex);
	return (NULL);
}

/// @brief loops until someone dies. It checks if the time_to_die has passed
/// and if so it sets the someoene_death to true. Prints the died message and 
/// waits wit usleep for better precision.
/// @param philo struct of the philosopher and the table.
/// @return 0
int	death_loop(t_p *philo)
{
	int	i;

	while (pthread_mutex_lock(&philo->table->print_mutex),
		philo->table->someoene_death == false)
	{
		pthread_mutex_unlock(&philo->table->print_mutex);
		i = 0;
		while (i < philo->table->number_of_philosophers)
		{
			pthread_mutex_lock(&philo->table->print_mutex);
			if (philo->count_eat == philo->table->times_has_to_eat)
				return (pthread_mutex_unlock(&philo->table->print_mutex), 0);
			if (philo->table->someoene_death == true)
				return (pthread_mutex_unlock(&philo->table->print_mutex), 0);
			if (mili_count() - philo[i].time_eaten >= philo->table->time_to_die)
			{
				philo->table->someoene_death = true;
				printf("%lld %d died\n",
					time_stamp(philo), philo->id + 1);
				return (pthread_mutex_unlock(&philo->table->print_mutex), 0);
			}
			pthread_mutex_unlock(&philo->table->print_mutex);
			i++;
		}
		pthread_mutex_lock(&philo->table->print_mutex);
		if (philo->table->someoene_death == true)
			return (pthread_mutex_unlock(&philo->table->print_mutex), 0);
		pthread_mutex_unlock(&philo->table->print_mutex);
		usleep(1000);
	}
	pthread_mutex_unlock(&philo->table->print_mutex);
	return (0);
}
