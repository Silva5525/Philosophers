/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:55:41 by wdegraf           #+#    #+#             */
/*   Updated: 2024/06/05 20:06:54 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int count(void *id)
{
	int i;
	int hold = (int)(long)id;
	i = 0;
	printf("[%d]philo says: %d\n", hold, hold);
	i++;
	id = (void *)(i + hold);
	pthread_exit (id);
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
			philo[j].id = j;
			if (pthread_create(&philo[j].thread, NULL, &count, (void *)(long)philo[j].id) != 0)
				return (-1);
			j++;
		}
		j = 0;
		while (i > j)
		{
			pthread_join(philo[j].thread, NULL);
			j++;
		}
		j = 0;
		while (i > j)
		{
			printf("[%d]philo says this time: %d\n", j, philo[j].id);
			j++;
		}
	}
	return (0);
}
