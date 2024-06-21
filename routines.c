/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:08:55 by wdegraf           #+#    #+#             */
/*   Updated: 2024/06/21 17:28:39 by wdegraf          ###   ########.fr       */
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
	if (print == true && philo->table->someoene_death == false)
	{
		pthread_mutex_lock(&philo->table->print_mutex);
		printf("%lld %d %s",
			time_stamp(philo->table->table_time), philo->id + 1, str);
		print = true;
		pthread_mutex_unlock(&philo->table->print_mutex);
	}
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

/// @brief split the be_alive function into 2 parts. So the eat and sleep part
/// happens here. only interesting part is the usleep_wile_eat_sleep function.
/// so check that out.
/// @param philo struct of the philosopher and the table.
static void	eat_sleep_repeat(t_p *philo)
{
	if (philo->table->number_of_philosophers >= 2
		&& philo->table->someoene_death == false)
	{
		pthread_mutex_lock(&philo->table->forks[philo->l_hand]);
		safe_print(philo, "has taken a fork\n");
		safe_print(philo, "is eating\n");
		usleep_wile_eat_sleep(philo, philo->table->time_to_eat);
		philo->count_eat++;
		philo->time_eaten = mili_count();
		pthread_mutex_unlock(&philo->table->forks[philo->l_hand]);
	}
	pthread_mutex_unlock(&philo->table->forks[philo->r_hand]);
	if (philo->table->someoene_death == true)
		return ;
	safe_print(philo, "is sleeping\n");
	usleep_wile_eat_sleep(philo, philo->table->time_to_sleep);
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
		usleep(200);
	while (!(philo->count_eat
			== philo->table->times_has_to_eat)
		&& philo->table->someoene_death == false)
	{
		pthread_mutex_lock(&philo->table->forks[philo->r_hand]);
		safe_print(philo, "has taken a fork\n");
		eat_sleep_repeat(philo);
		safe_print(philo, "is thinking\n");
	}
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

	while (philo->table->someoene_death == false)
	{
		i = 0;
		while (i < philo->table->number_of_philosophers
			&& philo->table->someoene_death == false)
		{
			if (mili_count() - philo[i].time_eaten >= philo->table->time_to_die)
				philo->table->someoene_death = true;
			if (philo->table->someoene_death == true)
			{
				printf("%lld %d died\n",
					time_stamp(philo->table->table_time), philo->id + 1);
				return (0);
			}
			i++;
		}
		if (philo->table->someoene_death == true)
			return (0);
		usleep(100);
	}
	return (0);
}
