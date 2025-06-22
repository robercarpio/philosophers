/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rober <rober@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:35:46 by rober             #+#    #+#             */
/*   Updated: 2025/06/20 13:31:50 by rober            ###   ########.fr       */
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
	if(len > 10)
		error_exit("Error: value is too big");
	return (number);
	
}
