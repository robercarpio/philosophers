/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rober <rober@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:56:49 by rober             #+#    #+#             */
/*   Updated: 2025/06/20 15:25:05 by rober            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	init(t_table *table)
{
	table->end_simulation = false;
	table->philos = safe_malloc(table->philo_number);
	
	
}