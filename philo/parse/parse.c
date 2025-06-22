/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rober <rober@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:23:59 by rober             #+#    #+#             */
/*   Updated: 2025/06/20 13:43:28 by rober            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	parse(t_table *table, char *argv[])
{
	table->philo_number = ft_atol(argv[1]);
	table->tt_die = ft_atol(argv[2]) * 1e3;
	table->tt_eat = ft_atol(argv[3]) * 1e3;
	table->tt_sleep = ft_atol(argv[4]) * 1e3;
	if (table->tt_die < 6e4
		|| table->tt_eat < 6e4
		|| table->tt_sleep < 6e4
	)
		error_exit("Error: timestamps minor than 60ms");
	if (argv[5])
		table->nbr_limit_meals = ft_atol(argv[5]);
	else
		table->nbr_limit_meals = -1;
}