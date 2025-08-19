/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio-cyepes <rcarpio-cyepes@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:37:35 by rober             #+#    #+#             */
/*   Updated: 2025/07/31 19:39:02 by rcarpio-cye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUX_H
# define AUX_H

# include "../philosophers.h"

char	**ft_split(char *s, char c);
int		ft_strlen(char *str);
char	*ft_substr(char *s, int start, int len);
void	*ft_calloc(int nmemb, int size);
char	**ft_split(char *s, char c);
void	ft_bzero(void *s, int n);
void	*ft_calloc(int nmemb, int size);
void	*ft_memcpy(void *dest, const void *src, int n);
char	*ft_strdup(char *s);
int		ft_strlcpy(char *dst, char *src, int size);
int		ft_strlen(char *str);
bool	is_digit(char c);
bool	is_space(char c);
char	*ft_substr(char *s, int start, int len);
char	*valid_number(char *str);
long	ft_atol(char *str);
void	*safe_malloc(int bytes);
void	safe_mutex(pthread_mutex_t *mutex, t_opcode opcode);
void	safe_thread(pthread_t *thread, void *(*foo)(void *), void *data, t_opcode opcode);
//getters setters
bool	simulation_finished(t_table *table);
long	get_long(pthread_mutex_t *mutex, long *value);
void	set_long(pthread_mutex_t *mutex, long *dest, long value);
bool	get_bool(pthread_mutex_t *mutex, bool *value);
void	set_bool(pthread_mutex_t *mutex, bool *dest, bool value);

#endif