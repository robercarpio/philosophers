/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio-cyepes <rcarpio-cyepes@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 19:50:53 by rcarpio-cye       #+#    #+#             */
/*   Updated: 2025/08/03 17:11:02 by rcarpio-cye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dinner.h"

static void	write_status_debug(t_philo_status status, t_philo *philo, long elapsed)
{
	if (TAKE_FIRST_FORK == status && !simulation_finished(philo->table))
		printf(W "%-6ld" RST " %d has taken the 1° fork\t\tB[%d]\n" RST,
			elapsed, philo->id, philo->right_f->id);
	else if (TAKE_SECOND_FORK == status && !simulation_finished(philo->table))
		printf(W "%-6ld" RST " %d has taken the 2° fork\t\tB[%d]\n" RST,
			elapsed, philo->id, philo->left_f->id);
	else if (EATING == status && !simulation_finished(philo->table))
		printf(W "%-6ld" C " %d is eating\t\tY[%ld]\n" RST,
			elapsed, philo->id, philo->meals_count);
	else if (SLEEPING == status && !simulation_finished(philo->table))
		printf(W "%-6ld" RST " %d is sleeping\n", elapsed, philo->id);
	else if (THINKING == status && !simulation_finished(philo->table))
		printf(W "%-6ld" RST " %d is thinking\n", elapsed, philo->id);
	else if (DIED == status)
		printf(R "\t\t%-6ld %d died\n" RST, elapsed, philo->id);
}



void	write_status(t_philo_status status, t_philo *philo, bool debug)
{
	long	elapsed;

	elapsed = gettime(MILLISECOND) - philo->table->start_simulation;
	if (philo->full)
		return ;
	safe_mutex(&philo->table->mutex_write, LOCK);
	if (debug)
		write_status_debug(status, philo, elapsed);
	else
	{
		if ((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status)
			&& !simulation_finished(philo->table))
			printf(W "%-6ld" RST " %d has taken a fork\n", elapsed, philo->id);
		else if (EATING == status && simulation_finished(philo->table))
			printf(W "%-6ld" C " %d is eating\n" RST, elapsed, philo->id);
		else if (SLEEPING == status && simulation_finished(philo->table))
			printf(W "%-6ld" RST " %d is sleeping\n", elapsed, philo->id);
		else if (THINKING == status && simulation_finished(philo->table))
			printf(W "%-6ld" RST " %d is thinking\n", elapsed, philo->id);
		else if (DIED == status)
			printf(R "%-6ld" C " %d died\n" RST, elapsed, philo->id);
	}
	safe_mutex(&philo->table->mutex_write, UNLOCK);
}

