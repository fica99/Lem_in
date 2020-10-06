/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_suurbale_update_graph.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:05:00 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/06 23:13:29 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static int		al_reverse_edges(t_node **nodes, size_t from, size_t to,
																size_t end)
{
	t_edge		*edge;
	int			weight;
	t_search	search;

	search = (t_search){from, True, to, True, 0, False};
	if (nodes[from]->is_in == False)
		edge = al_get_edge(&nodes[from]->edges_out, &search);
	else
		edge = al_get_edge(&nodes[from]->edges_in, &search);
	weight = edge->weight;
	edge->next = NULL;
	edge->weight *= -1;
	edge->from = to;
	edge->to = from;
	if (nodes[from]->is_in == False && to != end)
		al_add_edge(&nodes[to]->edges_in, edge, False);
	else
		al_add_edge(&nodes[to]->edges_out, edge, False);
	if (to != end)
		nodes[to]->is_in = (t_bool)((nodes[to]->is_in + 1) % 2);
	return (weight);
}

void			al_update_graph(t_graph *graph, int *arr_nodes, t_edge **edges)
{
	size_t	i;
	t_edge	*edge;
	int		weight;

	i = graph->graph_end;
	while (i != graph->graph_start)
	{
		weight = al_reverse_edges(graph->nodes, arr_nodes[i], i, graph->graph_end);
		edge = (t_edge *)ft_xmalloc(sizeof(t_edge));
		edge->from = arr_nodes[i];
		edge->to = i;
		edge->weight = weight;
		edge->next = *edges;
		*edges = edge;
		i = arr_nodes[i];
	}
}
