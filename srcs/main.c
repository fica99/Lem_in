/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:58:48 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/21 16:02:53 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int main(int argc, char **argv)
{
	t_graph	graph;
	size_t	i;
	t_paths	*paths;

	argc = 0;
	argv = NULL;
	graph.nb_nodes = 8;
	graph.graph_start = 0;
	graph.graph_end = 7;
	graph.malloc_nodes = 8;
	graph.nodes = (t_node**)ft_xmalloc(sizeof(t_node*) * 8);
	i = 0;
	while (i < 8)
	{
		graph.nodes[i] = (t_node*)ft_xmalloc(sizeof(t_node));
		ft_bzero((void*)graph.nodes[i], sizeof(t_node) * 8);
		++i;
	}
	graph.nodes[0]->edges = al_add_edge(&(graph.nodes[0]->edges), 0, 1, True);
	graph.nodes[0]->edges->weight = 1;
	graph.nodes[0]->edges = al_add_edge(&(graph.nodes[0]->edges), 0, 4, True);
	graph.nodes[0]->edges->weight = 1;
	graph.nodes[1]->edges = al_add_edge(&(graph.nodes[1]->edges), 1, 0, True);
	graph.nodes[1]->edges->weight = 1;
	graph.nodes[1]->edges = al_add_edge(&(graph.nodes[1]->edges), 1, 2, True);
	graph.nodes[1]->edges->weight = 1;
	graph.nodes[2]->edges = al_add_edge(&(graph.nodes[2]->edges), 2, 1, True);
	graph.nodes[2]->edges->weight = 1;
	graph.nodes[2]->edges = al_add_edge(&(graph.nodes[2]->edges), 2, 3, True);
	graph.nodes[2]->edges->weight = 1;
	graph.nodes[3]->edges = al_add_edge(&(graph.nodes[3]->edges), 3, 4, True);
	graph.nodes[3]->edges->weight = 1;
	graph.nodes[3]->edges = al_add_edge(&(graph.nodes[3]->edges), 3, 5, True);
	graph.nodes[3]->edges->weight = 1;
	graph.nodes[3]->edges = al_add_edge(&(graph.nodes[3]->edges), 3, 7, True);
	graph.nodes[3]->edges->weight = 1;
	graph.nodes[4]->edges = al_add_edge(&(graph.nodes[4]->edges), 4, 0, True);
	graph.nodes[4]->edges->weight = 1;
	graph.nodes[4]->edges = al_add_edge(&(graph.nodes[4]->edges), 4, 3, True);
	graph.nodes[4]->edges->weight = 1;
	graph.nodes[4]->edges = al_add_edge(&(graph.nodes[4]->edges), 4, 5, True);
	graph.nodes[4]->edges->weight = 1;
	graph.nodes[5]->edges = al_add_edge(&(graph.nodes[5]->edges), 5, 4, True);
	graph.nodes[5]->edges->weight = 1;
	graph.nodes[5]->edges = al_add_edge(&(graph.nodes[5]->edges), 5, 3, True);
	graph.nodes[5]->edges->weight = 1;
	graph.nodes[5]->edges = al_add_edge(&(graph.nodes[5]->edges), 5, 6, True);
	graph.nodes[5]->edges->weight = 1;
	graph.nodes[6]->edges = al_add_edge(&(graph.nodes[6]->edges), 6, 5, True);
	graph.nodes[6]->edges->weight = 1;
	graph.nodes[6]->edges = al_add_edge(&(graph.nodes[6]->edges), 6, 7, True);
	graph.nodes[6]->edges->weight = 1;
	graph.nodes[7]->edges = al_add_edge(&(graph.nodes[7]->edges), 7, 6, True);
	graph.nodes[7]->edges->weight = 1;
	graph.nodes[7]->edges = al_add_edge(&(graph.nodes[7]->edges), 7, 3, True);
	graph.nodes[7]->edges->weight = 1;
	paths = al_suurbale(&graph);

	return (0);
}
