/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:43:17 by wdegraf           #+#    #+#             */
/*   Updated: 2024/06/26 14:43:54 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// / @brief checks for leaks
// void leak_check(void)
// {
// 	system("leaks philo");
// }
// use at start of main atexit(leak_check);

/// @brief Philosopher simulation. The main checks the arguments,
/// then initializes the table and the Philosophers. Then it starts
/// the simulation with philosophy_so_deadly.
/// @param argc the number of arguments.
/// @param argv the argument values.
/// @return 0 if everything is fine. 1 if an error occured.
int	main(int argc, char **argv)
{
	t_p		*philo;
	t_ta	table;

	if (argc == 5 || argc == 6)
	{
		if (init_table(&table, argc, argv) == 1)
			return (1);
		philo = (t_p *)malloc(sizeof(t_p) * table.number_of_philosophers);
		if (!philo)
			return (write(2, "Error: malloc philo failed.\n", 29), 1);
		if (init_philo(philo, &table) == 1)
			return (1);
		if (philosophy_so_deadly(philo) == 1)
			return (1);
	}
	return (0);
}
