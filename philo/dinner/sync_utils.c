/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio-cyepes <rcarpio-cyepes@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:12:42 by rcarpio-cye       #+#    #+#             */
/*   Updated: 2025/08/24 17:02:12 by rcarpio-cye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dinner.h"

void	wait_all_threads(t_table *table)
{
	while (!get_bool(&table->mutex_table, &table->all_threads_ready))
		;
}

bool	all_threads_running(pthread_mutex_t *mutex,
	long *threads, long philo_nbr)
{
	bool	r;

	r = false;
	safe_mutex(mutex, LOCK);
	if (*threads == philo_nbr)
	{
		r = true;
	}
	safe_mutex(mutex, UNLOCK);
	return (r);
}

void	increase_long(pthread_mutex_t *mutex, long *value)
{
	safe_mutex(mutex, LOCK);
	(*value)++;
	safe_mutex(mutex, UNLOCK);
}

void	sync_philos(t_philo *philo)
{
	if (philo->table->philo_number % 2 == 0)
	{
		if (philo->id % 2 == 0)
			precise_usleep(3e4, philo->table);
	}
	else
	{
		if (philo->id % 2)
		{
			thinking(philo, true);
		}
	}
}
