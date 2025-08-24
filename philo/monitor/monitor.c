/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio-cyepes <rcarpio-cyepes@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:14:54 by rcarpio-cye       #+#    #+#             */
/*   Updated: 2025/08/24 17:08:49 by rcarpio-cye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"

static bool	philo_died(t_philo *philo)
{
	long	elapsed;
	long	time_to_die;

	if (get_bool(&philo->mutex_philo, &philo->full))
		return (false);
	elapsed = gettime(MILLISECOND) - get_long(&philo->mutex_philo,
			&philo->last_meal_time);
	time_to_die = philo->table->tt_die / 1e3;
	if (elapsed > time_to_die)
		return (true);
	return (false);
}

void	*monitor_dinner(void *data)
{
	t_table	*table;
	int		i;

	table = (t_table *)data;
	while (!all_threads_running(&table->mutex_table, &table->threads_running,
			table->philo_number))
	;
	while (!simulation_finished(table))
	{
		i = 0;
		while (i < table->philo_number && !simulation_finished(table))
		{
			if (philo_died(table->philos + i))
			{
				set_bool(&table->mutex_table, &table->end_simulation, true);
				write_status(DIED, table->philos + i, DEBUG_MODE);
			}
			i++;
		}
	}
	return (NULL);
}
