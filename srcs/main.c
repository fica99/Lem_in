/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:58:48 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/25 11:03:58 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int main(int argc, char **argv)
{
	t_graph	graph;
	size_t	i;
	t_edge	*edge;
	t_paths	*paths;

	argc = 0;
	argv = NULL;
	graph.nb_nodes = 3;
	graph.graph_start = 0;
	graph.graph_end = 2;
	graph.nodes = (t_node**)ft_xmalloc(sizeof(t_node*) * graph.nb_nodes);
	i = 0;
	while (i < graph.nb_nodes)
	{
		graph.nodes[i++] = (t_node*)ft_xmalloc(sizeof(t_node));
	}
	graph.nodes[0]->name = ft_strdup("A");
	graph.nodes[1]->name = ft_strdup("B");
	graph.nodes[2]->name = ft_strdup("C");
	edge = (t_edge*)ft_xmalloc(sizeof(t_edge));
	edge->weight = 1;
	edge->from = 0;
	edge->to = 1;
	al_add_edge(&graph.nodes[0]->edges_out, edge, False);
	edge = (t_edge*)ft_xmalloc(sizeof(t_edge));
	edge->weight = 1;
	edge->from = 0;
	edge->to = 1;
	al_add_edge(&graph.nodes[1]->edges_in, edge, False);

	edge = (t_edge*)ft_xmalloc(sizeof(t_edge));
	edge->weight = 1;
	edge->from = 1;
	edge->to = 0;
	al_add_edge(&graph.nodes[0]->edges_in, edge, False);
	edge = (t_edge*)ft_xmalloc(sizeof(t_edge));
	edge->weight = 1;
	edge->from = 1;
	edge->to = 0;
	al_add_edge(&graph.nodes[1]->edges_out, edge, False);



	edge = (t_edge*)ft_xmalloc(sizeof(t_edge));
	edge->weight = 1;
	edge->from = 0;
	edge->to = 2;
	al_add_edge(&graph.nodes[0]->edges_out, edge, False);
	edge = (t_edge*)ft_xmalloc(sizeof(t_edge));
	edge->weight = 1;
	edge->from = 0;
	edge->to = 2;
	al_add_edge(&graph.nodes[2]->edges_in, edge, False);

	edge = (t_edge*)ft_xmalloc(sizeof(t_edge));
	edge->weight = 1;
	edge->from = 2;
	edge->to = 0;
	al_add_edge(&graph.nodes[0]->edges_in, edge, False);
	edge = (t_edge*)ft_xmalloc(sizeof(t_edge));
	edge->weight = 1;
	edge->from = 2;
	edge->to = 0;
	al_add_edge(&graph.nodes[2]->edges_out, edge, False);




	edge = (t_edge*)ft_xmalloc(sizeof(t_edge));
	edge->weight = 1;
	edge->from = 1;
	edge->to = 2;
	al_add_edge(&graph.nodes[1]->edges_out, edge, False);
	edge = (t_edge*)ft_xmalloc(sizeof(t_edge));
	edge->weight = 1;
	edge->from = 1;
	edge->to = 2;
	al_add_edge(&graph.nodes[2]->edges_in, edge, False);

	edge = (t_edge*)ft_xmalloc(sizeof(t_edge));
	edge->weight = 1;
	edge->from = 2;
	edge->to = 1;
	al_add_edge(&graph.nodes[2]->edges_out, edge, False);
	edge = (t_edge*)ft_xmalloc(sizeof(t_edge));
	edge->weight = 1;
	edge->from = 2;
	edge->to = 1;
	al_add_edge(&graph.nodes[1]->edges_in, edge, False);


	paths = al_suurbale(&graph);
	int nb_ants = 100;
	lem_in_print_paths(paths, graph.nodes, nb_ants);
	al_del_paths(&paths);

	// free graph
	return (0);
}
