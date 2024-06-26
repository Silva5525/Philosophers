/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:55:41 by wdegraf           #+#    #+#             */
/*   Updated: 2024/06/28 13:53:04 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/// @brief initializes the mutex-forks. The forks are the mutexes which the
/// Philosophers use to eat. The number of forks is equal to the number of
/// Philosophers.
/// @param table struct of the philosopher and the table.
/// @return 0 if everything is fine. 1 if an error occured.
int	manifest_forks(t_ta *table)
{
	int	i;

	i = 0;
	table->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* table->number_of_philosophers);
	if (!table->forks)
		return (write(2, "Error: malloc table->forks failed.\n", 36), 1);
	while (i < table->number_of_philosophers)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (write(2, "Error: mutex init forks failed.\n", 33), 1);
		i++;
	}
	return (0);
}

/// @brief inits all values of the table->struct. This struct holds
/// all the values which all Philosophers have in common.
/// @param table->the table->struct.
/// @param argc argument count
/// @param argv argumment valuess
/// @return 1 if an error occured. 0 if everything is fine.
int	init_table(t_ta *table, int argc, char **argv)
{
	if (!ft_isdigit(argv[1]) || ft_atoi(argv[1]) < 1)
		return (write(2, "Error: argv[1] = no positive number.\n", 38), 1);
	table->number_of_philosophers = ft_atoi(argv[1]);
	if (!ft_isdigit(argv[2]) || ft_atoi(argv[2]) < 1)
		return (write(2, "Error: argv[2] = no positive number.\n", 38), 1);
	table->time_to_die = ft_atoi(argv[2]);
	if (!ft_isdigit(argv[3]) || ft_atoi(argv[3]) < 1)
		return (write(2, "Error: argv[3] = no positive number.\n", 38), 1);
	table->time_to_eat = ft_atoi(argv[3]);
	if (!ft_isdigit(argv[4]) || ft_atoi(argv[4]) < 1)
		return (write(2, "Error: argv[4] = no positive number.\n", 38), 1);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		if (!ft_isdigit(argv[5]) || ft_atoi(argv[5]) < 1)
			return (write(2, "Error: argv[5] = no positive number.\n", 38), 1);
		table->times_has_to_eat = ft_atoi(argv[5]);
	}
	else
		table->times_has_to_eat = -1;
	table->table_time = mili_count();
	table->someoene_death = false;
	printf("time in ms %lld\n", table->table_time);
	return (0);
}

/// @brief initializes the values of the Philosophers.
/// @param philo the struct of the Philosophers.
/// @param table the struct of the table.
/// @return 0 if everything is fine. 1 if an error occured.
int	init_philo(t_p *philo, t_ta *table)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		philo[i].id = i;
		philo[i].table = table;
		philo[i].l_hand = i;
		philo[i].r_hand = (i + 1);
		if (philo[i].r_hand == table->number_of_philosophers)
			philo[i].r_hand = 0;
		philo[i].count_eat = 0;
		philo[i].time_eaten = mili_count();
		i++;
	}
	if (manifest_forks(table) == 1)
		return (1);
	if (pthread_mutex_init(&table->print_mutex, NULL) != 0)
		return (write(2, "Error: pthread_mutex_init failed.\n", 35), 1);
	if (pthread_mutex_init(&table->print_mutex2, NULL) != 0)
		return (write(2, "Error: pthread_mutex_init2 failed.\n", 36), 1);
	if (pthread_mutex_init(&table->print_mutex3, NULL) != 0)
		return (write(2, "Error: pthread_mutex_init3 failed.\n", 36), 1);
	return (0);
}

/// @brief this function handels the loops of pthread_create, death_loop and
/// pthread_join and uses free_destroy to free the memory and destroy
/// the mutexes.
/// @param philo struct of the philosopher and the table.
/// @return 0 if everything is fine. 1 if an error occured.
int	philosophy_so_deadly(t_p *philo)
{
	int	i;

	i = 0;
	while (pthread_mutex_lock(&philo->table->print_mutex)
		, i < philo->table->number_of_philosophers
		&& philo->table->someoene_death == false)
	{
		pthread_mutex_unlock(&philo->table->print_mutex);
		if (pthread_create(&philo[i].live, NULL, be_alive, &philo[i]) != 0)
			return (free_destroy(philo), 1);
		i++;
	}
	pthread_mutex_unlock(&philo->table->print_mutex);
	death_loop(philo);
	return (free_destroy(philo), 0);
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
