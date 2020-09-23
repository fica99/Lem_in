#ifndef VALIDATOR_H
# define VALIDATOR_H

# define VAL_ERROR -42

typedef enum
{
	ERR_OPTION,
	ERR_ARG,
	ERR_EMPTY,
	ERR_INVALID_LINE,
	ERR_NOANTS,
	ERR_NOROOMS,
	ERR_INVALID_VALUES,
	ERR_NOSTART,
	ERR_NOEND,
	ERR_ROOM_LOOP,
	ERR_NOROOM_INFO,
	ERR_REDEFINED,
	ERR_NOSOLUTION
}			t_lemin_errors;

/*
** File val_start.c
*/

int			val_start_validation(int argc, char **argv);
int			val_check_options(char **argv);
int			val_check_arguments(char **argv);
int			val_check_program_option(char *arg, char *options,
				int (f)(int error_index, char *arg, int usage_needed));
int			val_read_stdinput(void);

/*
** File val_errors.c
*/

int			val_errors(int error_index, char *arg, int usage_needed);

#endif