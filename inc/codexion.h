#ifndef CODEXION_H
# define CODEXION_H

#include <stdio.h>
#include <limits.h>
#include <string.h>


typedef enum scheduler_ops
{
    FIFO,
    EDF
}                       t_scheduler;

struct args
{
    int					number_of_coders;
	long long			time_to_burnout;
	long long			time_to_compile;
	long long			time_to_debug;
	long long			time_to_refactor;
	int					number_of_compiles_required;
	long long			dongle_cooldown;
    t_scheduler         scheduler;

};

typedef struct args     t_args;


/* parser  */
int parser(int argc, char **argv, t_args *args);
int is_digit(char **argv);


/* utils  */
long long	long_atoi(const char *str);




#endif
