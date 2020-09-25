/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_suurbale_update_graph.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:05:00 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/25 04:30:02 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static void		al_reverse_edges(t_node **nodes, size_t from, size_t to)
{
	t_edge		*edge;
	t_search	search;

	search = (t_search){to, True, from, True, 0, False};
	edge = al_get_edge(&nodes[to]->edges_out, &search);
	ft_memdel((void**)&edge);
	edge = al_get_edge(&nodes[from]->edges_in, &search);
	ft_memdel((void**)&edge);
	search = (t_search){from, True, to, True, 0, False};
	edge = al_get_edge(&nodes[from]->edges_out, &search);
	edge->next = NULL;
	edge->weight = -1;
	edge->from = to;
	edge->to = from;
	al_add_edge(&nodes[to]->edges_in, edge, False);
	edge = al_get_edge(&nodes[to]->edges_in, &search);
	edge->next = NULL;
	edge->weight = -1;
	edge->from = to;
	edge->to = from;
	al_add_edge(&nodes[from]->edges_out, edge, False);
}


void			al_update_graph(t_graph *graph, int *arr_nodes, t_edge **edges)
{
	size_t	i;
	t_edge	*edge;

	i = graph->graph_end;
	while (i != graph->graph_start)
	{
		edge = (t_edge *)ft_xmalloc(sizeof(t_edge));
		edge->from = arr_nodes[i];
		edge->to = i;
		edge->weight = 1;
		edge->next = *edges;
		*edges = edge;
		al_reverse_edges(graph->nodes, arr_nodes[i], i);
		i = arr_nodes[i];
	}

}
