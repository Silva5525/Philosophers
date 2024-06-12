/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:57:19 by wdegraf           #+#    #+#             */
/*   Updated: 2024/06/12 13:17:30 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

/// @brief s_philo holds all the values which are unique to each Philosopher.
/// @param id the id of the Philosopher.

typedef struct s_philo
{
	int				id;
	pthread_t		live;
	t_ta			*table;
}	t_p;

/// @brief s_table holds all the values which all Philosophers
/// have in common. And represents the world in which the Philosophers
/// are simulated.
/// @param number_of_philosophers the number of Philosophers.
/// @param time_to_die the time in ms after a Philosopher dies.
/// @param time_to_eat the time in ms a Philosopher needs to eat.
/// @param time_to_sleep the time in ms a Philosopher needs to sleep.
/// @param times_has_to_eat the number of times a Philosopher has to eat.
/// @param table_time the time in ms when the simulation started.
typedef struct s_table
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_has_to_eat;
	bool			someoene_death;
	size_t			table_time;
	// pthread_mutex_t	fork;
}	t_ta;

//////////////////// utils.c ////////////////////
int		ft_atoi(const char *str);
int		ft_isdigit(char *d);
size_t	mili_count(void);

#endif
