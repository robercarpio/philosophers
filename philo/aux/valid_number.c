/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio-cyepes <rcarpio-cyepes@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:35:46 by rober             #+#    #+#             */
/*   Updated: 2025/08/24 16:42:34 by rcarpio-cye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

char	*valid_number(char *str)
{
	int		len;
	char	*number;

	while (is_space(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		error_exit("Error: negative number");
	if (!is_digit(*str))
		error_exit("Error: is not a correct digit");
	number = str;
	while (is_digit(*str++))
		len++;
	if (len > 18)
		error_exit("Error: value is too big");
	return (number);
}
