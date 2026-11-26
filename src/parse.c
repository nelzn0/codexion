/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 15:33:55 by username          #+#    #+#             */
/*   Updated: 2026/11/26 16:53:43 by nda-roch         ###   ########.fr       */
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
	while (i <= 7)
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
