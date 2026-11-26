/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fields.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 16:49:20 by username          #+#    #+#             */
/*   Updated: 2026/11/26 17:19:24 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/codexion.h"

int	int_field(char *str, int *field, char *error_msg)
{
	long long	converted_int;

	if (check_long_overflow(str))
		return (1);
	else
	{
		converted_int = long_atoi(str);
		if (converted_int > INT_MAX)
		{
			fprintf(stderr, "Error: %s is %s\n", error_msg, str);
			return (1);
		}
		else
		{
			*field = converted_int;
			return (0);
		}
	}
}

int	long_field(char *str, long long *field, char *error_msg)
{
	long long	converted_long;

	if (check_long_overflow(str))
	{
		fprintf(stderr, "Error: %s is %s\n", error_msg, str);
		return (1);
	}
	else
	{
		converted_long = long_atoi(str);
		*field = converted_long;
		return (0);
	}
}

int	scheduler_field(char *str, t_scheduler *field, char *error_msg)
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
	{
		fprintf(stderr, "Error: %s is %s\n", error_msg, str);
		return (1);
	}
}

int	zero_field(long long value, char *error_msg)
{
	if (value == 0)
	{
		fprintf(stderr, "Error: %s is %lld \n", error_msg, value);
		return (1);
	}
	else
		return (0);
}

int	write_into_fields(char **argv, t_args *args)
{
	int	errors;
	int	status;

	errors = 0;
	status = int_field(argv[1], &args->number_of_coders, "number_of_coders");
	errors += status;
	if (status == 0)
		errors += zero_field(args->number_of_coders, "number_of_coders");
	status = long_field(argv[2], &args->time_to_burnout, "time_to_burnout");
	errors += status;
	if (status == 0)
		errors += zero_field(args->time_to_burnout, "time_to_burnout");
	errors += long_field(argv[3], &args->time_to_compile, "time_to_compile");
	errors += long_field(argv[4], &args->time_to_debug, "time_to_debug");
	errors += long_field(argv[5], &args->time_to_refactor, "time_to_refactor");
	status = int_field(argv[6], &args->number_of_compiles_required,
			"number_of_compiles_required");
	errors += status;
	if (status == 0)
		errors += zero_field(args->number_of_compiles_required,
				"number_of_compiles_required");
	errors += long_field(argv[7], &args->dongle_cooldown, "dongle_cooldown");
	errors += scheduler_field(argv[8], &args->scheduler, "scheduler");
	return (errors);
}
