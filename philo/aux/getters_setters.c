/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio-cyepes <rcarpio-cyepes@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:59:39 by rcarpio-cye       #+#    #+#             */
/*   Updated: 2025/07/31 18:09:48 by rcarpio-cye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

void	set_bool(pthread_mutex_t *mutex, bool *dest, bool value)
{
	safe_mutex(mutex,LOCK);
	*dest = value;
	safe_mutex(mutex,UNLOCK);
}

bool	get_bool(pthread_mutex_t *mutex, bool *value)
{
	bool	r;
	safe_mutex(mutex,LOCK);
	r = *value;
	safe_mutex(mutex,UNLOCK);
	return (r);
}

void	set_long(pthread_mutex_t *mutex, long *dest, long value)
{
	safe_mutex(mutex,LOCK);
	*dest = value;
	safe_mutex(mutex,UNLOCK);
}

long	get_long(pthread_mutex_t *mutex, long *value)
{
	long	r;
	safe_mutex(mutex,LOCK);
	r = *value;
	safe_mutex(mutex,UNLOCK);
	return (r);
}

bool	simulation_finished(t_table *table)
{
	return (get_bool(&table->mutex_table,&table->end_simulation));
}