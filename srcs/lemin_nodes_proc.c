/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_nodes_proc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 14:46:00 by sschmele          #+#    #+#             */
/*   Updated: 2020/09/25 15:56:28 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "graph.h"

void			lemin_nodesarray_clean(t_node ***nodes, size_t nb_nodes)
{
	size_t		i;
	t_node		**ptr_nodes;

	i = 0;
	ptr_nodes = (*nodes);
	if (!nodes || !ptr_nodes)
		return ;
	while (i < nb_nodes)
	{
		if (ptr_nodes[i])
			lemin_node_clean(&ptr_nodes[i]);
		i++;
	}
	free(*nodes);
	*nodes = NULL;
}

t_node			*lemin_node_init(void)
{
	t_node		*new_node;

	new_node = (t_node*)ft_xmalloc(sizeof(t_node));
	new_node->name = NULL;
	new_node->x = -1;
	new_node->y = -1;
	new_node->edges_in = lemin_edge_init();
	new_node->edges_out = lemin_edge_init();
	return (new_node);
}

void			lemin_node_clean(t_node **node)
{
	if (!node || !(*node))
		return ;
	free((*node)->name);
	(*node)->name = NULL;
	lemin_edge_clean(&(*node)->edges_in);
	lemin_edge_clean(&(*node)->edges_out);
	free(*node);
	*node = NULL;
}

t_edge			*lemin_edge_init(void)
{
	t_edge		*new_edge;

	new_edge = (t_edge*)ft_xmalloc(sizeof(t_edge));
	new_edge->from = -1;
	new_edge->to = -1;
	new_edge->weight = -1;
	new_edge->next = NULL;
	return (new_edge);
}

void			lemin_edge_clean(t_edge **begin_edge)
{
	t_edge		*runner;

	if (!(begin_edge) || !(*begin_edge))
		return ;
	while (*begin_edge)
	{
		runner = (*begin_edge)->next;
		free((*begin_edge));
		*begin_edge = runner;
	}
	*begin_edge = NULL;
}