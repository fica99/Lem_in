/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_suurbale_update_graph.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:05:00 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/06 13:46:17 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static int		al_reverse_from_edge(t_node **nodes, size_t from,
												size_t to, t_search *search)
{
	t_edge	*edge;
	int		weight;

	if (nodes[from]->is_in == False)
	{
		edge = al_get_edge(&nodes[from]->edges_out, search);
		weight = edge->weight;
		edge->next = NULL;
		edge->weight = -1;
		edge->from = to;
		edge->to = from;
		al_add_edge(&nodes[to]->edges_in, edge, False);
	}
	else
	{
		edge = al_get_edge(&nodes[from]->edges_in, search);
		weight = edge->weight;
		edge->next = NULL;
		edge->weight = -1;
		edge->from = to;
		edge->to = from;
		al_add_edge(&nodes[to]->edges_out, edge, False);
	}
	return (weight);
}

static int		al_reverse_to_edge(t_node **nodes, size_t from,
												size_t to, t_search *search)
{
	t_edge	*edge;
	int		weight;

	if (nodes[from]->is_in == False)
	{
		edge = al_get_edge(&nodes[to]->edges_in, search);
		weight = edge->weight;
		edge->next = NULL;
		edge->weight = -1;
		edge->from = to;
		edge->to = from;
		al_add_edge(&nodes[from]->edges_out, edge, False);
	}
	else
	{
		edge = al_get_edge(&nodes[to]->edges_out, search);
		weight = edge->weight;
		edge->next = NULL;
		edge->weight = -1;
		edge->from = to;
		edge->to = from;
		al_add_edge(&nodes[from]->edges_in, edge, False);
	}
	return (weight);
}

static int		al_reverse_edges(t_node **nodes, size_t from, size_t to)
{
	t_edge		*edge;
	t_search	search;
	int			weight;

	search = (t_search){to, True, from, True, 0, False};
	edge = al_get_edge(&nodes[to]->edges_out, &search);
	ft_memdel((void**)&edge);
	edge = al_get_edge(&nodes[from]->edges_in, &search);
	ft_memdel((void**)&edge);
	search = (t_search){from, True, to, True, 0, False};
	weight = al_reverse_from_edge(nodes, from, to, &search);
	al_reverse_to_edge(nodes, from, to, &search);
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
		weight = al_reverse_edges(graph->nodes, arr_nodes[i], i);
		edge = (t_edge *)ft_xmalloc(sizeof(t_edge));
		edge->from = arr_nodes[i];
		edge->to = i;
		edge->weight = weight;
		edge->next = *edges;
		*edges = edge;
		if (i != graph->graph_end)
			graph->nodes[i]->is_in = (t_bool)((graph->nodes[i]->is_in + 1) % 2);
		i = arr_nodes[i];
	}
}
