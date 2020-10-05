/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_nodes_search.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 13:24:19 by sschmele          #+#    #+#             */
/*   Updated: 2020/10/05 20:17:30 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "graph.h"

size_t			lemin_search_name(t_node **nodes,
					size_t nb_nodes, char *new_name)
{
	size_t		i;

	i = 0;
	while (i < nb_nodes && nodes[i])
	{
		if (nodes[i]->name)
			if (ft_strcmp(new_name, nodes[i]->name) == 0)
				return (i);
		i++;
	}
	return (SIZE_MAX);
}

size_t			lemin_search_coord(t_node **nodes,
					size_t nb_nodes, int x, int y)
{
	size_t		i;

	i = 0;
	while (i < nb_nodes && nodes[i])
	{
		if (nodes[i]->x != -1 &&
				nodes[i]->y != -1)
			if (x == nodes[i]->x && y == nodes[i]->y)
				return (i);
		i++;
	}
	return (SIZE_MAX);
}