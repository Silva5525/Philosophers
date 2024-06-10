/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:55:41 by wdegraf           #+#    #+#             */
/*   Updated: 2024/06/10 15:53:45 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_table(t_ta table, int argc, char **argv)
{
	if (ft_isdigit(argv[1]) || ft_atoi(argv[1]) < 1)
		return (write(2 , "Error: argv[1] = no positive number.\n", 38), 1);
	table.number_of_philosophers = ft_atoi(argv[1]);
	if (ft_isdigit(argv[2]) || ft_atoi(argv[2]) < 1)
		return (write(2 , "Error: argv[2] = no positive number.\n", 38), 1);
	table.time_to_die = ft_atoi(argv[2]);
	if (ft_isdigit(argv[3]) || ft_atoi(argv[3]) < 1)
		return (write(2 , "Error: argv[3] = no positive number.\n", 38), 1);
	table.time_to_eat = ft_atoi(argv[3]);
	if (ft_isdigit(argv[4]) || ft_atoi(argv[4]) < 1)
		return (write(2 , "Error: argv[4] = no positive number.\n", 38), 1);
	table.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		if (ft_isdigit(argv[5]) || ft_atoi(argv[5]) < 1)
			return (write(2 , "Error: argv[5] = no positive number.\n", 38), 1);
		table.times_has_to_eat = ft_atoi(argv[5]);
	}
	else
		table.times_has_to_eat = -42;
	printf("tesst\n");
	return 0;
		
}

int	main(int argc, char **argv)
{
	t_p		*philo;
	t_ta	table;

	if (argc == 5 || argc == 6)
	{
		if (init_table(table, argc, argv) == 1)
			return (1);
	}
	return (0);
}
