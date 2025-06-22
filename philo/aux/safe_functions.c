/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rober <rober@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:12:21 by rober             #+#    #+#             */
/*   Updated: 2025/06/20 15:48:52 by rober            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

void	*safe_malloc(int bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if(!ret)
		error_exit("Error: malloc fail");
	return(ret);
}

void	safe_mutex(pthread_mutex_t *mutex, t_opcode opcode)
{
	if	(opcode == LOCK)
		pthread_mutex_lock(mutex);
	else if (opcode == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if (opcode == INIT)
		pthread_mutex_init(mutex,NULL);
	else if (opcode == DESTROY)
		pthread_mutex_destroy(mutex);
	else
		error_exit("Error: wrong opcode for mutex handle");
}