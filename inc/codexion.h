/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 16:51:54 by username          #+#    #+#             */
/*   Updated: 2026/11/27 11:57:40 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <stdio.h>
# include <limits.h>
# include <string.h>
# include <pthread.h>

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

typedef struct s_args			t_args;

struct s_dongle
{
	int						id;
	int						is_held;
	long long				time_to_free;
	pthread_mutex_t			mutex;
	pthread_cond_t			coders_waiting;

};

typedef struct s_dongle			t_dongle;

struct s_coder
{
	int			id;
	t_dongle	*left_d;
	t_dongle	*right_d;
	long long	last_compile_start;
	int			compile_count;
	long long	time_to_burnout;
};

typedef struct s_coder			t_coder;

struct s_entry
{
	t_coder			*coder;
	long long		arrival_n;
};

typedef struct s_entry			t_entry;

struct s_heap
{
	int			capacity;
	t_entry		*items;
	int			size;
	t_scheduler	scheduler_type;
};

typedef struct s_heap			t_heap;

struct s_shared_state
{
	t_coder			*coders;
	int				sim_running;
	t_dongle		*dongles;
	pthread_mutex_t	log_mutex;
	pthread_mutex_t	state_mutex;
	long long		start_time;
	int				n_coders;
};

typedef struct s_shared_state	t_shared_state;

/* parser  */
int			parser(int argc, char **argv, t_args *args);
int			is_digit(char **argv);
int			check_long_overflow(char *str);
int			write_into_fields(char **argv, t_args *args);

/* utils  */
long long	long_atoi(const char *str);

#endif
