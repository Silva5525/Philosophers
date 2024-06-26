/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:57:19 by wdegraf           #+#    #+#             */
/*   Updated: 2024/06/26 15:02:43 by wdegraf          ###   ########.fr       */
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
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	print_mutex2;
	pthread_mutex_t	print_mutex3;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_has_to_eat;
	bool			someoene_death;
	long long		table_time;
}	t_ta;

/// @brief s_philo holds all the values which are unique to each Philosopher.
/// @param id the ident-number of the Philosopher.

typedef struct s_philosopher
{
	int				id;
	int				r_hand;
	int				l_hand;
	int				count_eat;
	long long		time_eaten;
	pthread_t		live;
	t_ta			*table;
}	t_p;

///////////////////// philo.c ////////////////////
int			philosophy_so_deadly(t_p *philo);
void		*be_alive(void *link);
int			philosophy_so_deadly(t_p *philo);
int			init_philo(t_p *philo, t_ta *table);
int			init_table(t_ta *table, int argc, char **argv);
int			manifest_forks(t_ta *table);

//////////////////// utils.c ////////////////////
int			ft_atoi(const char *str);
int			ft_isdigit(char *d);
long long	time_stamp(t_p *philo);
long long	mili_count(void);
void		free_destroy(t_p *philo);
void		safe_print(t_p *philo, char *str);

//////////////////// routines.c ////////////////////

void		usleep_wile_eat_sleep(t_p *philo, long long time);
int			death_loop(t_p *philo);
int			eat_sleep_repeat(t_p *philo);
void		safe_print(t_p *philo, char *str);

#endif
