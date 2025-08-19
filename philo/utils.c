/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio-cyepes <rcarpio-cyepes@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:27:32 by rober             #+#    #+#             */
/*   Updated: 2025/08/19 22:19:56 by rcarpio-cye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "aux/aux.h"
#include <unistd.h>

void	clean(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while(i < table->philo_number)
	{
		philo = table->philos + i;
		safe_mutex(&philo->mutex_philo,DESTROY);
		i++;
	}
	safe_mutex(&table->mutex_write,DESTROY);
	safe_mutex(&table->mutex_table,DESTROY);
	free(table->forks);
	free(table->philos);
}

void	error_exit(char *str)
{
	printf(R "%s \n",str);
	exit(EXIT_FAILURE);
}

long	gettime(t_time_code time_code)
{
	struct timeval	tv;
	if (gettimeofday(&tv, NULL))
		error_exit("Error: gettime failed");
	if (SECOND == time_code)
		return(tv.tv_sec + (tv.tv_usec/1e5));
	else if (MILLISECOND == time_code)
		return(tv.tv_sec * 1e3) + tv.tv_usec / 1e3;
	else if (MICROSECOND == time_code)
		return (tv.tv_sec * 1e6) + tv.tv_usec;
	else
		error_exit("Error: wrong input to gettijme()");
	return (1337);
}

void	precise_usleep(long secs, t_table *table)
{
	long	start;
	long	elapsed;
	long	remaining;
	
	start = gettime(MICROSECOND);
	while (gettime(MICROSECOND) - start < secs)
	{
		if(simulation_finished(table))
			break;
		elapsed = gettime(MICROSECOND) - start;
		remaining = secs - elapsed;
		if (remaining > 1e3)
			usleep(remaining / 2);
		else
		{
			while(gettime(MICROSECOND) - start < secs)
				;
		}
	}
}
