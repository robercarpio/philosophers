/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rober <rober@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:37:35 by rober             #+#    #+#             */
/*   Updated: 2025/06/20 15:48:49 by rober            ###   ########.fr       */
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

#endif