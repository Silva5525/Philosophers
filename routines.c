/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:08:55 by wdegraf           #+#    #+#             */
/*   Updated: 2024/06/26 15:07:33 by wdegraf          ###   ########.fr       */
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
int	eat_sleep_repeat(t_p *philo)
{
	if (philo->table->number_of_philosophers >= 2)
	{
		pthread_mutex_lock(&philo->table->forks[philo->l_hand]);
		safe_print(philo, "has taken a fork\n");
		safe_print(philo, "is eating\n");
		usleep_wile_eat_sleep(philo, philo->table->time_to_eat);
		pthread_mutex_lock(&philo->table->print_mutex);
		philo->count_eat++;
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

/// @brief splits the death_loop in the part which checks in the loop
/// evry philo if he died someone_death is true or if 
/// count_eat = times_has_to_eat.
/// @param philo struct of the philosopher and the table.
/// @return 1 if it has to stop 0 if loop goes on.
static int	eat_or_die(t_p *philo)
{
	int	i;

	i = 0;
	while (i < philo->table->number_of_philosophers)
	{
		pthread_mutex_lock(&philo->table->print_mutex);
		if (philo->count_eat == philo->table->times_has_to_eat)
			return (pthread_mutex_unlock(&philo->table->print_mutex), 1);
		if (philo->table->someoene_death == true)
			return (pthread_mutex_unlock(&philo->table->print_mutex), 1);
		if (mili_count() - philo[i].time_eaten >= philo->table->time_to_die)
		{
			philo->table->someoene_death = true;
			printf("%lld %d died\n",
				time_stamp(philo), philo->id + 1);
			return (pthread_mutex_unlock(&philo->table->print_mutex), 1);
		}
		pthread_mutex_unlock(&philo->table->print_mutex);
		i++;
	}
	return (0);
}

/// @brief loops until someone dies. It checks if the time_to_die has passed
/// and if so it sets the someoene_death to true. Prints the died message and 
/// waits wit usleep for better precision.
/// @param philo struct of the philosopher and the table.
/// @return 0
int	death_loop(t_p *philo)
{
	while (pthread_mutex_lock(&philo->table->print_mutex),
		philo->table->someoene_death == false)
	{
		pthread_mutex_unlock(&philo->table->print_mutex);
		if (eat_or_die(philo) != 0)
			return (0);
		pthread_mutex_lock(&philo->table->print_mutex);
		if (philo->table->someoene_death == true)
			return (pthread_mutex_unlock(&philo->table->print_mutex), 0);
		pthread_mutex_unlock(&philo->table->print_mutex);
		usleep(1000);
	}
	pthread_mutex_unlock(&philo->table->print_mutex);
	return (0);
}
