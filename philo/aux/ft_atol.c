/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio-cyepes <rcarpio-cyepes@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:28:18 by rober             #+#    #+#             */
/*   Updated: 2025/08/24 16:16:29 by rcarpio-cye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

long	ft_atol(char *str)
{
	long	number;

	number = 0;
	str = valid_number(str);
	while (is_digit(*str))
		number = (number * 10) + (*str++ -48);
	if (number > INT_MAX)
		error_exit("Error: value is too big");
	return (number);
}
