/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:55:41 by wdegraf           #+#    #+#             */
/*   Updated: 2024/06/10 09:41:59 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *count(void *p)
{
	t_p *philo = (t_p *)p;
	int *hold = malloc(sizeof(int));
	if (!hold)
		return (NULL);
	*hold = philo->id + philo->all;
	printf("[%d]philo says: %d\n", philo->id, philo->all);
	return ((void*)hold);
}

int	main(int argc, char **argv)
{
	int i;
	int j;
	t_p *philo;
	
	j = 0;
	i = 0;
	if (argc == 2)
	{
		i = ft_atoi(argv[1]);
		philo = (t_p *)malloc(sizeof(t_p) * i);
		if (!philo)
			return (-1);
		while (i > j)
		{
			pthread_mutex_init(&philo[j].mutex, NULL);
			philo[j].id = j;
			philo[j].all = i;
			if (pthread_create(&philo[j].thread, NULL, &count, &philo[j]) != 0)
			{
				free(philo);
				return (-1);
			}
			j++;
		}
		j = 0;
		int sum = 0;
		while (i > j)
		{
			int *hold;
			if (pthread_join(philo[j].thread, (void **)&hold) != 0)
			{
				free(philo);
				return (-1);
			}
			j++;
			printf("[%d]philo says second time: %d\n", j, sum);
			sum += *hold;
			free(hold);
		}
		j = 0;
		while (i > j)
		{
			printf("[%d]philo says this time: %d\n", j, sum);
			j++;
		}
	}
	free(philo);
	return (0);
}
