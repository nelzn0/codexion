/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   utils.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/25 11:12:05 by username         #+#    #+#              */
/*   Updated: 2026/11/25 12:22:59 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "inc/codexion.h"

long long	long_atoi(const char *str)
{
	long long	n;
	long long	sym;

	n = 0;
	sym = 1;
	while ((*str >= 9 && *str <= 13) || (*str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sym = -1;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (n * sym);
}
