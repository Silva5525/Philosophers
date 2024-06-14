/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:08:55 by wdegraf           #+#    #+#             */
/*   Updated: 2024/06/14 14:16:28 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/// @brief 
/// @param link the void pointer to the t_p philo
/// @return 
void	*be_alive(void *link)
{
	t_p		*philo;

	philo = (t_p *)link;
	printf("Philosopher %d is alive\n", philo->id);
	return (NULL);
}
