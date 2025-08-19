/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio-cyepes <rcarpio-cyepes@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:48:55 by rcarpio-cye       #+#    #+#             */
/*   Updated: 2025/08/19 22:44:05 by rcarpio-cye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dinner.h"

void	thinking(t_philo *philo, bool pre_simulation) 
{
	long	time_to_eat;
	long	time_to_sleep;
	long	time_to_think;
	
	if (!pre_simulation)
		write_status(THINKING, philo, DEBUG_MODE);
	if(philo->table->philo_number % 2 == 0)
		return;
	time_to_eat = philo->table->tt_eat;
	time_to_sleep = philo->table->tt_sleep;
	time_to_think = time_to_eat * 2 - time_to_sleep;
	if (time_to_think < 0)
		time_to_think = 0;
	precise_usleep(time_to_think * 0.42, philo->table);
}

void	*lone_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_all_threads(philo->table);
	set_long(&philo->mutex_philo, &philo->last_meal_time, gettime(MILLISECOND));
	increase_long(&philo->table->mutex_table, &philo->table->threads_running);
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	while(!simulation_finished(philo->table))
		usleep(200);
	return (NULL);
}

static void	 eat(t_philo *philo)
{
	safe_mutex(&philo->right_f->fork,LOCK);
	write_status(TAKE_FIRST_FORK,philo,DEBUG_MODE);
	safe_mutex(&philo->left_f->fork,LOCK);
	write_status(TAKE_SECOND_FORK,philo,DEBUG_MODE);

	set_long(&philo->mutex_philo,&philo->last_meal_time,gettime(MILLISECOND));
	philo->meals_count++;
	write_status(EATING,philo,DEBUG_MODE);
	precise_usleep(philo->table->tt_eat, philo->table);
	if (philo->table->nbr_limit_meals > 0 && philo->meals_count == philo->table->nbr_limit_meals)
		set_bool(&philo->mutex_philo,&philo->full, true);
	safe_mutex(&philo->right_f->fork, UNLOCK);
	safe_mutex(&philo->left_f->fork, UNLOCK);
}

void	*dinner_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table);
	set_long(&philo->mutex_philo,&philo->last_meal_time,gettime(MILLISECOND));
	increase_long(&philo->table->mutex_table,&philo->table->threads_running);
	sync_philos(philo);
	while (!simulation_finished(philo->table))
	{
		if (philo->full)
			break;
		eat(philo);
		write_status(SLEEPING,philo,DEBUG_MODE);
		precise_usleep(philo->table->tt_sleep, philo->table);
		thinking(philo,false);
	}
	return (NULL);
}

void	dinner(t_table *table)
{
	int	i;

	i = 0;
	if (table->nbr_limit_meals == 0)
		return;
	else if (table->philo_number == 1)
		safe_thread(&table->philos[0].thread_id, lone_philo, &table->philos[0], CREATE);
	else
	{
		while(i < table->philo_number)
		{
			safe_thread(&table->philos[i].thread_id, dinner_simulation, &table->philos[i], CREATE);
			i++;
		}
	}
		safe_thread(&table->monitor, monitor_dinner, table, CREATE);
		table->start_simulation = gettime(MILLISECOND);
		set_bool(&table->mutex_table,&table->all_threads_ready,true);
		i = 0;
		while (i < table->philo_number)
		{
			safe_thread(&table->philos[i].thread_id, NULL, NULL, JOIN);
			i++;
		}
		set_bool(&table->mutex_table,&table->end_simulation, true);
		safe_thread(&table->monitor, NULL, NULL, JOIN);
}

