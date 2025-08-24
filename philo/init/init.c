/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio-cyepes <rcarpio-cyepes@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:56:49 by rober             #+#    #+#             */
/*   Updated: 2025/08/24 17:05:45 by rcarpio-cye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static void	assign_forks(t_philo *philo, t_fork *forks, int pos)
{
	int	philo_nbr;

	philo_nbr = philo->table->philo_number;
	philo->right_f = &forks[(pos + 1) % philo_nbr];
	philo->left_f = &forks[pos];
	if (philo->id % 2 == 0)
	{
		philo->right_f = &forks[pos];
		philo->left_f = &forks[(pos + 1) % philo_nbr];
	}
}

static void	philo_init(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_number)
	{
		table->philos[i].id = i + 1;
		table->philos[i].full = false;
		table->philos[i].meals_count = 0;
		table->philos[i].table = table;
		safe_mutex(&table->philos[i].mutex_philo, INIT);
		assign_forks(&table->philos[i], table->forks, i);
		i++;
	}
}

void	init(t_table *table)
{
	int	i;

	i = 0;
	table->end_simulation = false;
	table->all_threads_ready = false;
	table->threads_running = 0;
	table->philos = safe_malloc(sizeof(t_philo) * table->philo_number);
	if (!table->philos)
		error_exit(R "[ERROR] No se pudo reservar memoria para philos\n" RST);
	safe_mutex(&table->mutex_table, INIT);
	safe_mutex(&table->mutex_write, INIT);
	table->forks = safe_malloc(sizeof(t_fork) * table->philo_number);
	if (!table->forks)
		error_exit(R "[ERROR] No se pudo reservar memoria para forks\n" RST);
	while (i < table->philo_number)
	{
		safe_mutex(&table->forks[i].fork, INIT);
		table->forks[i].id = i;
		i++;
	}
	philo_init(table);
}
