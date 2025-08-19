/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio-cyepes <rcarpio-cyepes@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:53:30 by rober             #+#    #+#             */
/*   Updated: 2025/08/19 22:45:54 by rcarpio-cye      ###   ########.fr       */
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
#include <errno.h>
#include <unistd.h>

// to use printf
// printf(R "this is a red text" RST);
// printf(B "this is a blue text" RST);
# define W		"\033[37m" 
# define C		"\033[36m"
# define RST	"\033[0m"
# define R		"\033[1;31m"
# define B		"\033[1;34m"
# define G		"\033[1;32m"
# define Y		"\033[1;33m"

// write function
#define DEBUG_MODE 1

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_opcode;

typedef enum	e_time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND
}	t_time_code;

typedef enum	e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED
}	t_philo_status;

struct	s_table;

typedef struct	s_fork
{
	pthread_mutex_t	fork;
	int				id;
}	t_fork;

typedef struct	s_philo
{
	int				id;
	t_fork			*right_f;	//firts fork
	t_fork			*left_f;	//second fork
	bool			full;
	long			meals_count;
	long			last_meal_time;
	pthread_t		thread_id;
	pthread_mutex_t	mutex_philo;
	struct s_table	*table;
	
}	t_philo;

// typedef struct	s_fork
// {
// 	pthread_mutex_t	fork;
// 	int				id;
// }	t_fork;

typedef struct	s_table
{
	long			philo_number;
	long			tt_die;
	long			tt_sleep;
	long			tt_eat;
	long			nbr_limit_meals;
	long			start_simulation;
	long			threads_running;
	bool			end_simulation;
	bool			all_threads_ready;
	pthread_mutex_t	mutex_table;
	pthread_mutex_t	mutex_write;
	pthread_t		monitor;
	t_fork			*forks;
	t_philo			*philos;
}	t_table;

void	error_exit(char *str);
long	gettime(t_time_code time_code);
void	precise_usleep(long secs, t_table *table);
void	clean(t_table *table);

#endif