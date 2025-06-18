/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rober <rober@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:53:30 by rober             #+#    #+#             */
/*   Updated: 2025/06/18 16:17:47 by rober            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>
# include <pthread.h>

// to use printf
// printf(R "this is a red text" RST);
// printf(B "this is a blue text" RST);

# define RST	"\033[0m"
# define R		"\033[1;31m"
# define B		"\033[1;34m"
# define G		"\033[1;32m"
# define Y		"\033[1;33m"

struct	s_table;

typedef struct	s_philo
{
	int				id;
	pthread_mutex_t	*left_f;
	pthread_attr_t	*right_f;
	bool			full;
	long			meals_count;
	long			last_meal_time;
	pthread_t		thread_id;
	struct s_table	*table;
	
}	t_philo;

typedef struct	s_fork
{
	pthread_mutex_t	fork;
	int				id;
}	t_fork;

typedef struct	s_table
{
	long	philo_number;
	long	tt_die;
	long	tt_sleep;
	long	tt_eat;
	long	nbr_limit_meals;
	long	start_simulation;
	bool	end_simulation;
	t_fork	*forks;
	t_philo	*philos;
}	t_table;

void	error_exit(char *str);

#endif