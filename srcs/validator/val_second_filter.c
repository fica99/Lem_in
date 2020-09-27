/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_second_filter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 20:35:49 by sschmele          #+#    #+#             */
/*   Updated: 2020/09/27 13:32:27 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "validator.h"

int			val_invalid_values(char *map, int map_size)
{
	int		i;
	t_graph	farm;
	int		ants;

	ants = val_getants(map);
	if (ants == VAL_ERROR)
		return (VAL_ERROR);
	farm = lemin_graph_init();
	i = ft_strchri(map, VAL_ENTER);
	if (val_getrooms(map, map_size, &i) == VAL_ERROR)
		return (VAL_ERROR);
	if (val_getlinks(map, map_size, &i) == VAL_ERROR)
		return (VAL_ERROR);
	return (0);
}

int			val_getants(char *map)
{
	int		ants;

	ants = ft_atoi(map);
	printf("%d\n", ants);
	if (map[0] == '0' || map[0] == VAL_DASH)
		return (val_errors(ERR_NOANTS, NULL, 0, 0));
	if (ants < 1)
		return (val_errors(ERR_EXTRAANTS, NULL, 0, 0));
	lemin_antsum_methods(ants, 1);
	return (ants);
}

int			val_getrooms(char *map, int map_size, int *i)
{
	char	name[VAL_MAXROOMNAME];
	char	coord[2][VAL_MAXROOMCOORD];
	int		flag;
	int		answer;

	flag = 0;
	ft_bzero(name, VAL_MAXROOMNAME);
	ft_bzero(coord, 2);
	while ((*i) < map_size)
	{
		val_pass_comments(map, i);
		flag = val_pass_startend(map, i);
		answer = val_check_room_pattern(map, i, name, coord);
		if (answer == VAL_ERROR)
			return (VAL_ERROR);
		if (answer == STOP)
			return (0);
		(*i)++;
	}
	return (0);
}

int			val_getlinks(char *map, int map_size, int *i)
{
	return (0);
}

int			val_pass_spaces(char *map, int *i)
{
	if (map[*i] == VAL_SPACE)
		while (map[*i] && map[*i] == VAL_SPACE)
			(*i)++;
	return (0);
}