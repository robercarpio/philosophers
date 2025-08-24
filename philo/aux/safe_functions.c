/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio-cyepes <rcarpio-cyepes@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:12:21 by rober             #+#    #+#             */
/*   Updated: 2025/08/24 16:42:09 by rcarpio-cye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

void	*safe_malloc(int bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (!ret)
		error_exit("Error: malloc fail");
	return (ret);
}

static void	handle_mutex_error(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (EINVAL == status && (LOCK == opcode || UNLOCK == opcode))
		error_exit("Error: the value specified by mutex is invalid");
	else if (EINVAL == status && INIT == opcode)
		error_exit("Error: the value specified by attr is invalid");
	else if (EDEADLOCK == status)
		error_exit
		("Error: A deadlock would occur if thread blocked waiting for mutex");
	else if (EPERM == status)
		error_exit("Error: the current thread does not hold a lock on mutex");
	else if (ENOMEM == status)
		error_exit("Error: the process cannot allocate enough memory "
			"to create another mutex");
	else if (EBUSY == status)
		error_exit("Error: Mutex is locked");
}

void	safe_mutex(pthread_mutex_t *mutex, t_opcode opcode)
{
	if (opcode == LOCK)
		handle_mutex_error(pthread_mutex_lock(mutex), opcode);
	else if (opcode == UNLOCK)
		handle_mutex_error(pthread_mutex_unlock(mutex), opcode);
	else if (opcode == INIT)
		handle_mutex_error(pthread_mutex_init(mutex, NULL), opcode);
	else if (opcode == DESTROY)
		handle_mutex_error(pthread_mutex_destroy(mutex), opcode);
	else
		error_exit("Error: wrong opcode for mutex handle");
}

static void	handle_thread_error(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (EAGAIN == status)
		error_exit("Error: no resources to create another thread");
	else if (EPERM == status)
		error_exit("Error: the caller does not have appropiate permission");
	else if (EINVAL == status && CREATE == opcode)
		error_exit("Error: the value specified by att is invalid");
	else if (EINVAL == status && (JOIN == opcode || DETACH == opcode))
		error_exit("Error: the value specified by thread is not joinable");
	else if (ESRCH == status)
		error_exit("Error: no thread could be found corresponding to that "
			"specified by given thread ID, "
			"thread");
	else if (EDEADLK == status)
		error_exit("Error: a deadlock was detected or the value of thread "
			"specifies the calling "
			"thread");
}

void	safe_thread(pthread_t *thread, void *(*foo)(void *),
					void *data, t_opcode opcode)
{
	if (CREATE == opcode)
		handle_thread_error(pthread_create(thread, NULL, foo, data), opcode);
	else if (JOIN == opcode)
		handle_thread_error(pthread_join(*thread, NULL), opcode);
	else if (DETACH == opcode)
		handle_thread_error(pthread_detach(*thread), opcode);
	else
		error_exit("Error: wrong opcode for thread_handle: "
			"use <CREATE> <JOIN> "
			"<DETACH>");
}
