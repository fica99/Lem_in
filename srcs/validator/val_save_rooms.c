/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_save_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 21:15:08 by sschmele          #+#    #+#             */
/*   Updated: 2020/10/04 23:14:43 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "validator.h"
#include "graph.h"

int			val_check_roomdraft(char name[VAL_MAXROOMNAME],
				char coord[2][VAL_MAXROOMCOORD], t_graph *farm, int flag)
{
	int		new_x;
	int		new_y;

	if (val_check_startenddraft(farm, flag) == VAL_ERROR)
		return (VAL_ERROR);
	if ((new_x = val_check_coorddraft(coord[0])) == VAL_ERROR)
		return (VAL_ERROR);
	if ((new_y = val_check_coorddraft(coord[1])) == VAL_ERROR)
		return (VAL_ERROR);
	if ((*farm).nodes && (*farm).nodes[0])
	{
		if (lemin_search_name((*farm).nodes,
				(*farm).nb_nodes, name) != SIZET_MAX)
			return (val_errors(ERR_REDEFINED, name, '\0', 0));
		if (lemin_search_coord((*farm).nodes,
				(*farm).nb_nodes, new_x, new_y) != SIZET_MAX)
			return (val_errors(ERR_REDEFINED, name, '\0', 0));
	}
	val_save_room(name, new_x, new_y, farm);
	if (flag == 's')
		(*farm).graph_start = (*farm).nb_nodes - 1;
	else if (flag == 'e')
		(*farm).graph_end = (*farm).nb_nodes - 1;
	return (0);
}

int			val_check_startenddraft(t_graph *farm, int flag)
{
	if (flag == 's' && (int)(*farm).graph_start != -1)
		return(val_errors(ERR_START_REDEFINED, NULL, 0, 0));
	else if (flag == 'e' && (int)(*farm).graph_end != -1)
		return(val_errors(ERR_END_REDEFINED, NULL, 0, 0));
	return (0);
}

int			val_check_coorddraft(char coord[VAL_MAXROOMCOORD])
{
	int		new_coord;
	
	if (coord[0] == VAL_DASH)
		return (val_errors(ERR_INVALID_COORD, coord, '\0', 0));
	new_coord = ft_atoi(coord);
	if (new_coord < 0)
		return (val_errors(ERR_INVALID_COORD, coord, '\0', 0));
	return (new_coord);
}

int			val_save_room(char name[VAL_MAXROOMNAME],
				int x, int y, t_graph *farm)
{
	if ((*farm).nodes == NULL)
	{
		(*farm).nodes_len = DEFAULT_NODES_LEN;
		(*farm).nodes = (t_node**)ft_xmalloc(sizeof(t_node*)
			* (*farm).nodes_len);
		(*farm).nb_nodes = 0;
	}
	if ((*farm).nb_nodes == (*farm).nodes_len)
	{
		(*farm).nodes = lemin_nodesarray_realloc((*farm).nodes,
			(*farm).nodes_len, (*farm).nodes_len * 2);
		(*farm).nodes_len *= 2;
	}
	(*farm).nodes[(*farm).nb_nodes] = lemin_node_init(ft_strdup(name), x, y);
	(*farm).nb_nodes++;
	return (0);
}