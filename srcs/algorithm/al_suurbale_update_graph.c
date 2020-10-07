/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_suurbale_update_graph.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:05:00 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/07 20:54:03 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static int		al_reverse_edges(t_node **nodes, t_bell_ford_params *params, size_t i, size_t end)
{
	t_edge		*edge;
	int			weight;
	t_search	search;

	search = (t_search){params[i].prev, True, i, True, 0, False};
	if (params[i].from_out == True)
		edge = al_get_edge(&nodes[params[i].prev]->edges_out, &search);
	else
		edge = al_get_edge(&nodes[params[i].prev]->edges_in, &search);
	weight = edge->weight;
	edge->next = NULL;
	edge->weight *= -1;
	edge->from = i;
	edge->to = params[i].prev;
	if (params[i].from_out == True)
		al_add_edge(&nodes[i]->edges_in, edge, False);
	else
		al_add_edge(&nodes[i]->edges_out, edge, False);
	return (weight);
}

void			al_update_graph(t_graph *graph, t_bell_ford_params *params, t_edge **edges)
{
	size_t	i;
	t_edge	*edge;
	int		weight;

	i = graph->graph_end;
	while (i != graph->graph_start)
	{
		weight = al_reverse_edges(graph->nodes, params, i, graph->graph_end);
		edge = (t_edge *)ft_xmalloc(sizeof(t_edge));
		edge->from = params[i].prev;
		edge->to = i;
		edge->weight = weight;
		edge->next = *edges;
		*edges = edge;
		i = params[i].prev;
	}
}
