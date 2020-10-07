/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_second_filter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 20:35:49 by sschmele          #+#    #+#             */
/*   Updated: 2020/10/07 00:12:02 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "validator.h"
#include "graph.h"

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
	i++;
	if (val_getrooms(map, map_size, &i, &farm) == VAL_ERROR)
	{
		lemin_graph_clean(farm);
		return (VAL_ERROR);
	}
	if (val_getlinks(map, map_size, &i, &farm) == VAL_ERROR)
	{
		lemin_graph_clean(farm);
		return (VAL_ERROR);
	}
	lemin_graph_methods(&farm, 1);
	
	// lemin_nodesarray_print(farm.nodes, farm.nb_nodes);
	// ft_printf("\nstart index is %d, end index is %d\n",
	// 	(int)farm.graph_start, (int)farm.graph_end);
	
	return (0);
}

int			val_getants(char *map)
{
	int		ants;

	ants = ft_atoi(map);
	if (map[0] == '0' || map[0] == VAL_DASH)
		return (val_errors(ERR_NOANTS, NULL, 0, 0));
	if (ants < 1)
		return (val_errors(ERR_EXTRAANTS, NULL, 0, 0));
	lemin_antsum_methods(ants, 1);
	return (ants);
}

int			val_getrooms(char *map, int map_size, int *i, t_graph *farm)
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
		flag = val_pass_startend(map, i);
		val_pass_comments(map, i);
		if (map[*i] == VAL_HASH)
			continue ;
		answer = val_check_room_pattern(map, i, name, coord);
		if (answer == VAL_ERROR || answer == STOP)
			return ((answer == VAL_ERROR) ? VAL_ERROR : 0);
		if (answer == 1)
			if ((answer = val_check_roomdraft(name,
					coord, farm, flag)) == VAL_ERROR)
				return (VAL_ERROR);
		(*i)++;
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
		j++;
		*i = j;
	}
	return (flag);
}

int			val_getlinks(char *map, int map_size, int *i, t_graph *farm)
{
	char	name1[VAL_MAXROOMNAME];
	char	name2[VAL_MAXROOMNAME];
	int		answer;

	if ((*i) == map_size)
		return (val_errors(ERR_NOSOLUTION, NULL, 0, 0));
	ft_bzero(name1, VAL_MAXROOMNAME);
	ft_bzero(name2, VAL_MAXROOMNAME);
	while ((*i) < map_size)
	{
		val_pass_comments(map, i);
		answer = val_check_link_pattern(map, i, name1, name2);
		if (answer == VAL_ERROR)
			return (VAL_ERROR);
		if (answer == 1)
			if ((answer = val_check_linkdraft(name1, name2, farm)) == VAL_ERROR)
				return (VAL_ERROR);
		(*i)++;
	}
	return (0);
}
