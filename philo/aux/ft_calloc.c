/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio-cyepes <rcarpio-cyepes@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:37:12 by rcarpio-          #+#    #+#             */
/*   Updated: 2025/07/30 16:58:23 by rcarpio-cye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

void	*ft_calloc(int nmemb, int size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr != NULL)
	{
		ft_bzero(ptr, nmemb * size);
		return (ptr);
	}
	return (NULL);
}
