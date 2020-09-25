/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_graph_proc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 14:29:17 by sschmele          #+#    #+#             */
/*   Updated: 2020/09/25 15:28:03 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "graph.h"

static t_graph	g_farm;

void			lemin_graph_init(void)
{
	g_farm.graph_start = -1;
	g_farm.graph_end = -1;
	g_farm.nb_nodes = -1;
	g_farm.nodes = NULL;
}

t_graph			lemin_get_graph(void)
{
	return (g_farm);
}

int				lemin_save_graphints(size_t value, char flag)
{
	if (flag == 'n')
		g_farm.nb_nodes = value;
	else if (flag == 's')
		g_farm.graph_start = value;
	else if (flag == 'e')
		g_farm.graph_end = value;
	else
		return (-1);
	return (0);
}

int				lemin_save_graph_nodes(t_node **value)
{
	g_farm.nodes = value;
	return (0);
}

void			lemin_graph_clean(void)
{
	lemin_nodesarray_clean(&g_farm.nodes, g_farm.nb_nodes);
	g_farm.graph_start = -1;
	g_farm.graph_end = -1;
	g_farm.nb_nodes = -1;
}