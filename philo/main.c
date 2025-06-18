/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rober <rober@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:08:20 by rober             #+#    #+#             */
/*   Updated: 2025/06/18 16:35:45 by rober            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	(void) argv;
	if (argc == 5 || argc == 6)
	{
		t_table	table;
		(void) table;
		//parse
		// parse(&table,argv);

		//init
		//init(&table)

		//start
		//start(&table)

		//leaks
		//clean(&table)
	}
	else
		error_exit("Wrong format input\n"
				G "Example: ./philo 5 800 200 200 [5]"RST);
	return (0);
}