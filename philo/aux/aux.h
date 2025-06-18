/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rober <rober@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:37:35 by rober             #+#    #+#             */
/*   Updated: 2025/06/18 17:03:35 by rober            ###   ########.fr       */
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
char	*ft_substr(char *s, int start, int len);

#endif