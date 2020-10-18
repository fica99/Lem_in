/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:12:16 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/18 13:08:08 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATOR_H
# define VALIDATOR_H

# define VAL_ERROR -42
# define STDIN_BUFFER 50
# define VAL_SPACE ' '
# define VAL_DASH '-'
# define VAL_ENTER '\n'
# define VAL_HASH '#'
# define VAL_MAXROOMNAME 256
# define VAL_MAXROOMCOORD 12

typedef enum
{
	ERR_OPTION,
	ERR_ARG,
	ERR_TERM,
	ERR_NOFARM,
	ERR_EMPTY,
	ERR_INVALID_LINE,
	ERR_SPACE_START,
	ERR_SPACE_END,
	ERR_NOANTS,
	ERR_EXTRAANTS,
	ERR_NOROOMS,
	ERR_NOSTART,
	ERR_START_REDEFINED,
	ERR_NOEND,
	ERR_END_REDEFINED,
	ERR_INVALID_COMMAND,
	ERR_NOCOMMAND,
	ERR_INVALID_ROOMNAME,
	ERR_NOROOM_INFO,
	ERR_ROOM_REDEFINED,
	ERR_INVALID_COORD,
	ERR_NOCOORD,
	ERR_EXTRACOORD,
	ERR_LINK_PATTERN,
	ERR_ROOM_LOOP,
	ERR_NOSOLUTION,
}	t_lemin_errors;

/*
** File val_start.c
*/

int			val_start_validation(int argc, char **argv);
int			val_read_stdinput(void);
int			val_check_map(char *map, int map_size);
int			val_check_farm(t_graph *farm);

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
** File val_help_funcs.c
*/

int			val_pass_spaces(char *map, int *i);
int			val_find_delimiter(char *map, int i);
int			val_isdelimiter(char *map, int i);
int			val_pass_comments(char *map, int *i, int flag);
int			val_pass_startend(char *map, int *i, int flag);

/*
** File val_first_filter.c
*/

int			val_invalid_lines(char *map, int map_size);
int			val_check_antsnum(char *map, int map_size);
int			val_invalid_startend(char *map, int map_size, int *i);
int			val_check_spaces(char *map, int i);
int			val_invalid_roomaftercommand(char *map,
				int map_size, int *i, int start);

/*
** File val_second_filter.c
*/

int			val_invalid_values(char *map, int map_size);
int			val_getfarm(char *map, int map_size, int *i, t_graph *farm);
int			val_getants(char *map);
int			val_getrooms(char *map, int map_size, int *i, t_graph *farm);
int			val_getlinks(char *map, int map_size, int *i, t_graph *farm);

/*
** File val_second_filter_rooms.c
*/

int			val_check_room_pattern(char *map, int *i,
				char name[VAL_MAXROOMNAME],
				char coord[2][VAL_MAXROOMCOORD]);
int			val_getroomsname(char *map, int *i,
				char *name, int beg_line);
int			val_getroomscoord(char *map, int *i,
				char coord[VAL_MAXROOMCOORD], int beg_line);
int			val_coord_invalid_error(char *map, int beg_line,
				int beg_value, int error);
int			val_roomblock_error(char *map, int *i, int beg_line,
				char coord[2][VAL_MAXROOMCOORD]);

/*
** File val_save_rooms.c
*/

int			val_check_roomdraft(char name[VAL_MAXROOMNAME],
				char coord[2][VAL_MAXROOMCOORD], t_graph *farm, int flag);
int			val_check_startenddraft(t_graph *farm, int flag);
int			val_check_coorddraft(char coord[VAL_MAXROOMCOORD]);
int			val_save_room(char name[VAL_MAXROOMNAME],
				int x, int y, t_graph *farm);

/*
** File val_second_filter_links.c
*/

int			val_check_link_pattern(char *map, int *i,
				char name1[VAL_MAXROOMNAME],
				char name2[VAL_MAXROOMNAME]);
int			val_getlink_roomsnames(char *map, int *i,
				char *name1, char *name2);
int			val_check_linkdraft(char name1[VAL_MAXROOMNAME],
				char name2[VAL_MAXROOMNAME], t_graph *farm);
int			val_save_link(size_t index1, size_t index2, t_graph *farm);
int			val_save_edge(size_t index1, size_t index2, t_edge *edge);

#endif
