/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parse.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/17 15:33:55 by username         #+#    #+#              */
/*   Updated: 2026/11/25 12:55:46 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "inc/codexion.h"

#define G_LONG_MAX "9223372036854775807"

int	is_digit(char **argv)
{
	int	i;
	int	c;

	i = 1;
	c = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			return (0);
		c = 0;
		while (argv[i][c])
		{
			if (!(argv[i][c] >= '0' && argv[i][c] <= '9'))
				return (0);
			c++;
		}
		i++;
	}
	return (1);
}

int	check_long_overflow(char *str)
{
	while (*str == '0' && str[1] != '\0')
		str++;
	if (strlen(str) > 19)
		return (1);
	if ((strlen(str) == 19) && (strcmp(str, G_LONG_MAX) > 0))
		return (1);
	else
		return (0);
}

int	int_field(char *str, int *field)
{
	long long	converted_int;

	if (check_long_overflow(str))
		return (1);
	else
	{
		converted_int = long_atoi(str);
		if (converted_int > INT_MAX)
			return (1);
		else
		{
			*field = converted_int;
			return (0);
		}
	}
}

int	long_field(char *str, long long *field)
{
	long long	converted_long;

	if (check_long_overflow(str))
		return (1);
	else
	{
		converted_long = long_atoi(str);
		*field = converted_long;
		return (0);
	}
}

int	scheduler_field(char *str, t_scheduler *field)
{
	if (strcmp(str, "fifo") == 0)
	{
		*field = FIFO;
		return (0);
	}
	else if (strcmp(str, "edf") == 0)
	{
		*field = EDF;
		return (0);
	}
	else
		return (1);
}

int	write_into_fields(char **argv, t_args *args)
{
	int	errors;

	errors = 0;
	errors += int_field(argv[1], &args->number_of_coders);
	if (args->number_of_coders == 0)
		errors += 1;
	errors += long_field(argv[2], &args->time_to_burnout);
	if (args->time_to_burnout == 0)
		errors += 1;
	errors += long_field(argv[3], &args->time_to_compile);
	errors += long_field(argv[4], &args->time_to_debug);
	errors += long_field(argv[5], &args->time_to_refactor);
	errors += int_field(argv[6], &args->number_of_compiles_required);
	if (args->number_of_compiles_required == 0)
		errors += 1;
	errors += long_field(argv[7], &args->dongle_cooldown);
	errors += scheduler_field(argv[8], &args->scheduler);
	return (errors);
}

int	parser(int argc, char **argv, t_args *args)
{
	int	errors;

	errors = 0;
	if (argc != 9)
	{
		fprintf(stderr, "ERROR: Must be 9 arguments\n");
		return (1);
	}
	else
	{
		if (is_digit(argv))
		{
			errors = write_into_fields(argv, args);
			if (errors != 0)
				return (1);
			else
				return (0);
		}
		else
		{
			fprintf(stderr, "ERROR: 1 or more arguments are not digits\n");
			return (1);
		}
	}
}
