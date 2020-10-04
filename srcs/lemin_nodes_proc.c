/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_nodes_proc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 14:46:00 by sschmele          #+#    #+#             */
/*   Updated: 2020/10/04 20:52:28 by sschmele         ###   ########.fr       */
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
	if (!nodes || !ptr_nodes || nb_nodes == 0)
		return ;
	while (i < nb_nodes && ptr_nodes[i])
	{
		lemin_node_clean(&ptr_nodes[i]);
		i++;
	}
	free(*nodes);
	*nodes = NULL;
}

t_node			**lemin_nodesarray_realloc(t_node **nodesarray,
					size_t nodes_size, size_t new_size)
{
	size_t		i;
	t_node		**new_nodesarray;

	new_nodesarray = (t_node**)ft_xmalloc(sizeof(t_node*)
		* new_size);
	i = 0;
	while (i < nodes_size && nodesarray[i])
	{
		new_nodesarray[i] = nodesarray[i];
		i++;
	}
	free(nodesarray);
	nodesarray = NULL;
	return (new_nodesarray);
}

t_node			*lemin_node_init(char *name, int x, int y)
{
	t_node		*new_node;

	new_node = (t_node*)ft_xmalloc(sizeof(t_node));
	new_node->name = name;
	new_node->x = x;
	new_node->y = y;
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
