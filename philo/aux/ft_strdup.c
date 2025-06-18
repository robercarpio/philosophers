/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rober <rober@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:44:43 by rcarpio-          #+#    #+#             */
/*   Updated: 2025/06/18 16:57:46 by rober            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

char	*ft_strdup(char *s)
{
	char	*str;

	str = malloc((ft_strlen(s) + 1));
	if (str != NULL)
	{
		ft_memcpy(str, s, ft_strlen(s) + 1);
		return (str);
	}
	return (str);
}