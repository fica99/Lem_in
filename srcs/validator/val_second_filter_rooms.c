/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_second_filter_rooms.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:32:35 by sschmele          #+#    #+#             */
/*   Updated: 2020/09/27 12:33:14 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "validator.h"

int			val_pass_comments(char *map, int *i)
{
	int		j;
	
	j = *i;
	if (j > 0 && map[j] == VAL_HASH && map[j + 1] &&
			map[j + 1] != VAL_HASH &&
			map[j - 1] == VAL_ENTER)
	{
		while (map[j] && map[j] != VAL_ENTER)
			j++;
		*i = j;
	}
	return (0);
}

int			val_pass_startend(char *map, int *i)
{
	int		j;
	int		flag;
	
	j = *i;
	flag = 0;
	if (j > 0 && map[j] == VAL_HASH && map[j + 1] &&
			map[j + 1] == VAL_HASH &&
			map[j - 1] == VAL_ENTER)
	{
		if (map[j + 2] && map[j + 2] == 's')
			flag = 's';
		else if (map[j + 2] && map[j + 2] == 'e')
			flag = 'e';
		while (map[j] && map[j] != VAL_ENTER)
			j++;
		*i = j;
	}
	return (flag);	
}

int			val_check_room_pattern(char *map, int *i,
				char name[VAL_MAXROOMNAME],
				char coord[2][VAL_MAXROOMCOORD])
{
	int		j;
	int		beg;

	j = *i;
	beg = 0;
	if (map[j] != VAL_ENTER)
	{
		while (map[j] && map[j] != VAL_ENTER && ft_isprint(map[j]))
		{
			if (map[j] == VAL_DASH)
				return (STOP);
			j++;
		}
		*i = j;
	}
	return (0);
}