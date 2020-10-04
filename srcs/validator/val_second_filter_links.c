/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_second_filter_links.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:28:31 by sschmele          #+#    #+#             */
/*   Updated: 2020/10/05 00:10:13 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "validator.h"

int			val_check_link_pattern(char *map, int *i,
				char name1[VAL_MAXROOMNAME],
				char name2[VAL_MAXROOMNAME])
{
	int		answer;
	int		beg_line;
	char	*ptr_name1;
	char	*ptr_name2;

	if (map[*i] && map[*i] != VAL_ENTER)
	{
		beg_line = *i;
		ptr_name1 = &name1[0];
		ptr_name2 = &name2[0];
		answer = val_getlink_roomsnames(map, i, ptr_name1, ptr_name2);
		if (answer == VAL_ERROR || !ptr_name1[0] || !ptr_name2[0])
		{
			val_errors(ERR_INVALID_LINE, map + beg_line, VAL_ENTER, 0);
			return (val_errors(ERR_LINK, NULL, 0, 0));
		}
		return (1);
	}
	return (0);
}

int			val_getlink_roomsnames(char *map, int *i,
				char *name1, char *name2)
{
	int		k;
	int		l;

	k = -1;
	ft_bzero(name1, VAL_MAXROOMNAME);
	while (map[*i + (++k)] && (!(map[*i + k] == VAL_SPACE ||
			map[*i + k] == VAL_ENTER ||
			(map[*i + k] == VAL_DASH && map[*i + k + 1] &&
			map[*i + k + 1] != VAL_SPACE))) && k < VAL_MAXROOMNAME)
		name1[k] = map[*i + k];
	if (map[*i + k] != VAL_DASH)
		return (VAL_ERROR);
	k++;
	l = -1;
	ft_bzero(name2, VAL_MAXROOMNAME);
	while (map[*i + k + (++l)] && (!(map[*i + k + l] == VAL_SPACE ||
			map[*i + k + l] == VAL_ENTER)) && l < VAL_MAXROOMNAME)
		name2[l] = map[*i + k + l];
	if (map[*i + k + l] && map[*i + k + l] != VAL_ENTER)
		return (VAL_ERROR);
	*i += k + l;
	return (0);
}

/*
** Checked here: if such rooms exists and if it is not a loop
*/

int			val_check_linkdraft(char name1[VAL_MAXROOMNAME],
				char name2[VAL_MAXROOMNAME], t_graph *farm)
{
	size_t	index1;
	size_t	index2;
	
	index1 = SIZET_MAX;
	index2 = SIZET_MAX;
	if ((*farm).nodes && (*farm).nodes[0])
	{
		index1 = lemin_search_name((*farm).nodes,
				(*farm).nb_nodes, name1);
		if (index1 == SIZET_MAX)
			return (val_errors(ERR_NOROOM_INFO, name1, '\0', 0));
		index2 = lemin_search_name((*farm).nodes,
				(*farm).nb_nodes, name2);
		if (index2 == SIZET_MAX)
			return (val_errors(ERR_NOROOM_INFO, name2, '\0', 0));
		if (index1 == index2)
			return (val_errors(ERR_ROOM_LOOP, name1, '\0', 0));
	}
	else
	{
		val_errors(ERR_NOROOM_INFO, name1, '\0', 0);
		return (val_errors(ERR_NOROOM_INFO, name2, '\0', 0));
	}
	if (val_save_link(index1, index2, farm) == VAL_ERROR)
		return (VAL_ERROR);
	return (0);
}

int			val_save_link(size_t index1, size_t index2, t_graph *farm)
{
	// t_node	*ptr_node;
	// t_edge	*ptr_edge;
	
	// ptr_node = (*farm).nodes[index1];
	// ptr_edge = ptr_node->edges_out;
	printf("saving links\n");
	return (0);
}