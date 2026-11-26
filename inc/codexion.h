/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 16:51:54 by username          #+#    #+#             */
/*   Updated: 2026/11/26 17:11:33 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <stdio.h>
# include <limits.h>
# include <string.h>

typedef enum scheduler_ops
{
	FIFO,
	EDF
}	t_scheduler;

struct s_args
{
	int			number_of_coders;
	long long	time_to_burnout;
	long long	time_to_compile;
	long long	time_to_debug;
	long long	time_to_refactor;
	int			number_of_compiles_required;
	long long	dongle_cooldown;
	t_scheduler	scheduler;

};

typedef struct s_args	t_args;

/* parser  */
int			parser(int argc, char **argv, t_args *args);
int			is_digit(char **argv);
int			check_long_overflow(char *str);
int			write_into_fields(char **argv, t_args *args);

/* utils  */
long long	long_atoi(const char *str);

#endif
