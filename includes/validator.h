#ifndef VALIDATOR_H
# define VALIDATOR_H

# define VAL_ERROR -42
# define STDIN_BUFFER 50
# define VAL_SPACE ' '
# define VAL_DASH '-'
# define VAL_ENTER '\n'
# define VAL_HASH '#'
# define VAL_MAXROOMNAME 256
# define VAL_MAXROOMCOORD 11

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
	ERR_NOSOLUTION,
	ERR_TERM,
	ERR_NOFARM,
	ERR_EXTRAANTS,
	ERR_SPACE_START,
	ERR_SPACE_END
}			t_lemin_errors;

/*
** File val_start.c
*/

int			val_start_validation(int argc, char **argv);
int			val_read_stdinput(void);
int			val_check_map(char *map, int map_size);

/*
** File val_arguments.c
*/

int			val_check_options(char **argv);
int			val_check_arguments(char **argv);
int			val_check_program_option(char *arg, char *options,
				int (f)(int error_index, char *arg, char end, int usage_needed));

/*
** File val_errors.c
*/

int			val_errors(int error_index, char *arg, char end, int usage_needed);

/*
** File val_first_filter.c
*/

int			val_invalid_lines(char *map, int map_size);
int			val_check_antsnum(char *map, int map_size);
int			val_invalid_startend(char *map, int map_size, int *i);
int			val_check_spaces(char *map, int i);

/*
** File val_second_filter.c
*/

int			val_invalid_values(char *map, int map_size);
int			val_getants(char *map);
int			val_getrooms(char *map, int map_size, int *i);
int			val_getlinks(char *map, int map_size, int *i);
int			val_pass_spaces(char *map, int *i);

/*
** File val_second_filter_rooms.c
*/

int			val_pass_comments(char *map, int *i);
int			val_pass_startend(char *map, int *i);
int			val_check_room_pattern(char *map, int *i,
				char name[VAL_MAXROOMNAME],
				char coord[2][VAL_MAXROOMCOORD]);

#endif