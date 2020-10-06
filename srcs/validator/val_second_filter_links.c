/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_second_filter_links.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:28:31 by sschmele          #+#    #+#             */
/*   Updated: 2020/10/06 18:45:49 by sschmele         ###   ########.fr       */
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
			return (val_errors(ERR_LINK_PATTERN, NULL, 0, 0));
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
	char	*p_name;
	
	index1 = SIZE_MAX;
	index2 = SIZE_MAX;
	if ((*farm).nodes && (*farm).nodes[0])
	{
		p_name = &name1[0];
		index1 = lemin_search_name((*farm).nodes, (*farm).nb_nodes, p_name);
		if (index1 == SIZE_MAX)
			return (val_errors(ERR_NOROOM_INFO, name1, '\0', 0));
		p_name = &name2[0];
		index2 = lemin_search_name((*farm).nodes, (*farm).nb_nodes, p_name);
		if (index2 == SIZE_MAX)
			return (val_errors(ERR_NOROOM_INFO, name2, '\0', 0));
		if (index1 == index2)
			return (val_errors(ERR_ROOM_LOOP, name1, '\0', 0));
	}
	else
		return (val_errors(ERR_NOROOMS, NULL, '\0', 0));
	if (val_save_link(index1, index2, farm) == VAL_ERROR)
		return (VAL_ERROR);
	return (0);
}

/*
** Done here:
** Example: nodes[0] = 'A', node[1] = 'B'
** @ptr_node = 0(A)
** @ptr_edge = ptr_node->edges_out for 0(A) where
** from 0, to 1
** @ptr_edge = ptr_node->edges_in for 0(A) where
** from 1, to 0
** @ptr_node = 1(B)
** @ptr_edge = ptr_node->edges_out for 1(B) where
** from 1, to 0
** @ptr_edge = ptr_node->edges_in for 1(B) where
** from 0, to 1
*/

int			val_save_link(size_t index1, size_t index2, t_graph *farm)
{
	t_node	*ptr_node;
	t_edge	*ptr_edge;
	
	if (!(*farm).nodes[index1] || !(*farm).nodes[index2])
		return (val_errors(ERR_NOSOLUTION, NULL, 0, 0));
	ptr_node = (*farm).nodes[index1];
	ptr_edge = ptr_node->edges_out;
	val_save_edge(index1, index2, ptr_edge);
	ptr_edge = ptr_node->edges_in;
	val_save_edge(index2, index1, ptr_edge);
	ptr_node = (*farm).nodes[index2];
	ptr_edge = ptr_node->edges_out;
	val_save_edge(index2, index1, ptr_edge);
	ptr_edge = ptr_node->edges_in;
	val_save_edge(index1, index2, ptr_edge);
	return (0);
}

int			val_save_edge(size_t index1, size_t index2, t_edge *edge)
{
	t_edge	*runner;
	t_edge	*ptr_edge;

	runner = edge;
	if ((int)edge->from == -1 || (int)edge->to == -1)
	{
		edge->from = index1;
		edge->to = index2;
		return (0);
	}
	while (runner->next)
	{
		if (runner->from == index1 && runner->to == index2)
			return (0);
		runner = runner->next;
	}
	runner->next = lemin_edge_init();
	ptr_edge = runner->next;
	ptr_edge->from = index1;
	ptr_edge->to = index2;
	return (0);
}