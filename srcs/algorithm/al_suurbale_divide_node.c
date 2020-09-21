/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_suurbale_divide_node.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:12:36 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/21 13:12:30 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

// static size_t	al_add_node(t_graph *graph)
// {
// 	t_node	*new_node;

// 	if (++graph->nb_nodes >= graph->malloc_nodes * (2 / 3))
// 		graph->nodes = (t_node **)ft_memrealloc_array((void***)&graph->nodes,
// 							graph->malloc_nodes, graph->malloc_nodes *= 2);
// 	new_node = (t_node *)ft_xmalloc(sizeof(t_node));
// 	ft_bzero((void*)new_node, sizeof(t_node));
// 	new_node->type = Middle;
// 	graph->nodes[graph->nb_nodes - 1] = new_node;
// 	return (graph->nb_nodes - 1);
// }

// void			al_divide_node(t_graph *graph, int node)
// {
// 	size_t	i;
// 	size_t	new_node_i;
// 	t_edge	*tmp;

// 	i = 0;
// 	new_node_i = al_add_node(graph);
// 	al_add_edge(graph, node, new_node_i, 0);
// 	while (i < new_node_i)
// 	{

// 		++i;
// 	}
// }
