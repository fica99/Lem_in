/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_second_filter_rooms.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:32:35 by sschmele          #+#    #+#             */
/*   Updated: 2020/09/28 23:50:27 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "validator.h"

int			val_check_room_pattern(char *map, int *i,
				char name[VAL_MAXROOMNAME],
				char coord[2][VAL_MAXROOMCOORD])
{
	int		answer;
	int		beg_line;
	char	*ptr_name;

	if (map[*i] && map[*i] != VAL_ENTER)
	{
		beg_line = *i;
		ptr_name = &name[0];
		answer = val_getroomsname(map, i, ptr_name, beg_line);
		if (answer != 0)
			return (answer);
		val_pass_spaces(map, i);
		if (val_getroomscoord(map, i, coord[0], beg_line) == VAL_ERROR)
			return (VAL_ERROR);
		val_pass_spaces(map, i);
		if (val_getroomscoord(map, i, coord[1], beg_line) == VAL_ERROR)
			return (VAL_ERROR);
		if (val_roomblock_error(map, i, beg_line, coord) == VAL_ERROR)
			return (VAL_ERROR);
		return (1);
	}
	return (0);
}

int			val_getroomsname(char *map, int *i,
				char *name, int beg_line)
{
	int		k;

	k = 0;
	while (map[*i + k] && (!(map[*i + k] == VAL_SPACE ||
			map[*i + k] == VAL_ENTER)) && k < VAL_MAXROOMNAME)
	{
		if (map[*i + k] == VAL_DASH && map[*i + k + 1] &&
				map[*i + k + 1] != VAL_SPACE)
			return (STOP);
		k++;
	}
	k = -1;
	ft_bzero(name, VAL_MAXROOMNAME);
	while (map[*i + (++k)] && (!(map[*i + k] == VAL_SPACE ||
			map[*i + k] == VAL_ENTER)) && k < VAL_MAXROOMNAME)
		name[k] = map[*i + k];
	if (map[*i + k] == VAL_ENTER)
	{
		val_errors(ERR_INVALID_LINE, map + beg_line, VAL_ENTER, 0);
		return (val_errors(ERR_NOROOM_INFO, map + beg_line, VAL_ENTER, 0));
	}
	*i += k;
	return (0);
}

int			val_getroomscoord(char *map, int *i,
				char coord[VAL_MAXROOMCOORD], int beg_line)
{
	int		k;
	int		max_roomcoord;

	k = -1;
	ft_bzero(coord, VAL_MAXROOMCOORD);
	max_roomcoord = VAL_MAXROOMCOORD - 1;
	(map[*i + 0] == '-' || map[*i + 0] == '+') ? k++ : 0;
	(map[*i + 0] == '-' || map[*i + 0] == '+') ? max_roomcoord++ : 0;
	while (map[*i + (++k)] && (!(map[*i + k] == VAL_SPACE ||
			map[*i + k] == VAL_ENTER)) && k < max_roomcoord)
	{
		if (!ft_isdigit(map[*i + k]))
			return (val_coord_invalid_error(map, beg_line,
				*i, ERR_INVALID_COORD));
	}
	if (ft_isdigit(map[*i + k]))
		return (val_coord_invalid_error(map, beg_line,
			*i, ERR_INVALID_COORD));
	k = -1;
	while (map[*i + (++k)] && (!(map[*i + k] == VAL_SPACE ||
			map[*i + k] == VAL_ENTER)) && k < max_roomcoord)
		coord[k] = map[*i + k];
	*i += k;
	return (0);
}

int			val_coord_invalid_error(char *map, int beg_line,
				int beg_value, int error)
{
	int		k;

	val_errors(ERR_INVALID_LINE, map + beg_line, VAL_ENTER, 0);
	k = val_find_delimiter(map, beg_value);
	if (error == ERR_INVALID_COORD)
		return (val_errors(error, map + beg_value,
			map[beg_value + k], 0));
	return (val_errors(error, NULL, 0, 0));
}

int			val_roomblock_error(char *map, int *i, int beg_line,
				char coord[2][VAL_MAXROOMCOORD])
{
	if (!coord[1] || coord[1][0] == '\0')
		return (val_coord_invalid_error(map, beg_line,
			beg_line, ERR_NOCOORD));
	if (map[*i] != VAL_ENTER)
	{
		val_errors(ERR_INVALID_LINE, map + beg_line,
			VAL_ENTER, 0);
		return (val_errors(ERR_EXTRACOORD, NULL, 0, 0));
	}
	return (0);
}