/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio-cyepes <rcarpio-cyepes@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:08:20 by rober             #+#    #+#             */
/*   Updated: 2025/08/19 21:41:05 by rcarpio-cye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "parse/parse.h"
#include "init/init.h"
#include "dinner/dinner.h"

int	main(int argc, char *argv[])
{
	if (argc == 5 || argc == 6)
	{
		t_table table;
		parse(&table, argv);
		printf(G "Iniciando simulación de filósofos...\n" RST);
		init(&table);
		dinner(&table); // Ejecuta la simulación
		clean(&table); // Si tienes función de limpieza, descomenta
	}
	else
		error_exit("Wrong format input\n"
			G "Example: ./philo 5 800 200 200 [5]"RST);
	return (0);
}