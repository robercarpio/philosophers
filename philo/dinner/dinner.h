/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio-cyepes <rcarpio-cyepes@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:55:50 by rober             #+#    #+#             */
/*   Updated: 2025/08/24 16:59:16 by rcarpio-cye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DINNER_H
# define DINNER_H

# include "../philosophers.h"
# include "../aux/aux.h"
# include "../monitor/monitor.h"

void	wait_all_threads(t_table *table);
void	write_status(t_philo_status status, t_philo *philo, bool debug);
void	dinner(t_table *table);
void	*dinner_simulation(void *data);
bool	all_threads_running(pthread_mutex_t *mutex,
			long *threads,
			long philo_nbr);

void	increase_long(pthread_mutex_t *mutex, long *value);
void	thinking(t_philo *philo, bool pre_simulation);
void	sync_philos(t_philo *philo);
#endif