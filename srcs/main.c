/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:58:48 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/24 22:19:37 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int main(int argc, char **argv)
{
	t_graph	graph;
	size_t	i;
	t_edge	*edge;
	t_path	*paths;

	argc = 0;
	argv = NULL;
	graph.nb_nodes = 2;
	graph.graph_start = 0;
	graph.graph_end = 1;
	graph.nodes = (t_node**)ft_xmalloc(sizeof(t_node*) * 2);
	i = 0;
	while (i < 2)
		graph.nodes[i++] = (t_node*)ft_xmalloc(sizeof(t_node));
	edge = (t_edge*)ft_xmalloc(sizeof(t_edge));
	edge->weight = 1;
	edge->from = 0;
	edge->to = 1;
	al_add_edge(graph.nodes, edge, 0, False);
	edge = (t_edge*)ft_xmalloc(sizeof(t_edge));
	edge->weight = 1;
	edge->from = 0;
	edge->to = 1;
	al_add_edge(graph.nodes, edge, 1, True);
	edge = (t_edge*)ft_xmalloc(sizeof(t_edge));
	edge->weight = 1;
	edge->from = 1;
	edge->to = 0;
	al_add_edge(graph.nodes, edge, 0, True);
	edge = (t_edge*)ft_xmalloc(sizeof(t_edge));
	edge->weight = 1;
	edge->from = 1;
	edge->to = 0;
	al_add_edge(graph.nodes, edge, 1, False);
	paths = al_suurbale(&graph);
	return (0);
}
