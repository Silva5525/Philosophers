/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:55:41 by wdegraf           #+#    #+#             */
/*   Updated: 2024/06/18 20:04:42 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int manifest_forks(t_ta *table)
{
	int i;

	i = 0;
	table->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * table->number_of_philosophers);
	if (!table->forks)
		return (write(2, "Error: malloc forks failed.\n", 29), 1);
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
static int	init_table(t_ta *table, int argc, char **argv)
{
	if (!ft_isdigit(argv[1]) || ft_atoi(argv[1]) < 1)
		return (write(2 , "Error: argv[1] = no positive number.\n", 38), 1);
	table->number_of_philosophers = ft_atoi(argv[1]);
	if (!ft_isdigit(argv[2]) || ft_atoi(argv[2]) < 1)
		return (write(2 , "Error: argv[2] = no positive number.\n", 38), 1);
	table->time_to_die = ft_atoi(argv[2]);
	if (!ft_isdigit(argv[3]) || ft_atoi(argv[3]) < 1)
		return (write(2 , "Error: argv[3] = no positive number.\n", 38), 1);
	table->time_to_eat = ft_atoi(argv[3]);
	if (!ft_isdigit(argv[4]) || ft_atoi(argv[4]) < 1)
		return (write(2 , "Error: argv[4] = no positive number.\n", 38), 1);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		if (!ft_isdigit(argv[5]) || ft_atoi(argv[5]) < 1)
			return (write(2 , "Error: argv[5] = no positive number.\n", 38), 1);
		table->times_has_to_eat = ft_atoi(argv[5]);
	}
	else
		table->times_has_to_eat = -42;
	table->table_time = mili_count();
	table->someoene_death = false;
	printf("time in ms %lld\n", table->table_time);
	return 0;
}

static int init_philo(t_p *philo, t_ta *table)
{
	int i;

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
		return (write(2, "Error: mutex init print_mutex failed.\n", 33), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_p		*philo;
	t_ta	table;
	int		i;

	if (argc == 5 || argc == 6)
	{
		if (init_table(&table, argc, argv) == 1)
			return (1);
		philo = (t_p *)malloc(sizeof(t_p) * table.number_of_philosophers);
		if (!philo)
			return (write(2, "Error: malloc philo failed.\n", 29), 1);
		if (init_philo(philo, &table) == 1)
			return (1);
		i = 0;
		while (i < table.number_of_philosophers)
		{
			if (pthread_create(&philo[i].live, NULL, be_alive, &philo[i]) != 0)
				return (free_destroy(philo), 1);
			i++;
		}
		i = 0;
		// while (i < table.number_of_philosophers)
		// {
		// 	if (mili_count() - philo[i].time_eaten >= philo->table->time_to_die)
		// 		philo->table->someoene_death = true;
		// 	if (philo->table->someoene_death == true)
		// 	{
		// 		safe_print(philo, "died a very painfull and slow death so i see him in the terminal suffer.\n");
		// 		break ;
		// 	}
		// 	i++;
		// }
		// i = 0;
		while (i < table.number_of_philosophers && table.someoene_death == false)
		{
			if (pthread_join(philo[i].live, NULL) != 0)
				return (free_destroy(philo), 1);
			i++;
		}
		free_destroy(philo);
	}
	return (0);
}
