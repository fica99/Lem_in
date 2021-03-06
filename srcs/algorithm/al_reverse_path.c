/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_reverse_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:05:00 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/09 18:54:48 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static int		al_reverse_edges(t_node **nodes,
					t_bell_ford_params params[][2], size_t i, t_bool to_out)
{
	t_edge		*edge;
	int			weight;
	t_search	search;

	search = (t_search){params[i][to_out].prev, True, i, True, 0, False};
	edge = ((to_out) ? al_get_edge(&nodes[params[i][to_out].prev]->edges_in,
	&search) : al_get_edge(&nodes[params[i][to_out].prev]->edges_out,
																	&search));
	weight = edge->weight;
	edge->next = NULL;
	edge->weight *= -1;
	edge->from = i;
	edge->to = params[i][to_out].prev;
	if (to_out)
		al_add_edge(&nodes[i]->edges_out, edge, False);
	else
		al_add_edge(&nodes[i]->edges_in, edge, False);
	return (weight);
}

void			al_reverse_path(t_graph *graph, t_bell_ford_params params[][2],
																t_edge **edges)
{
	size_t	i;
	t_edge	*edge;
	int		weight;
	t_bool	to_out;

	i = graph->graph_end;
	to_out = False;
	while (i != graph->graph_start)
	{
		weight = al_reverse_edges(graph->nodes, params, i, to_out);
		if ((int)i != params[i][to_out].prev)
		{
			edge = (t_edge *)ft_xmalloc(sizeof(t_edge));
			edge->from = params[i][to_out].prev;
			edge->to = i;
			edge->weight = weight;
			edge->next = *edges;
			*edges = edge;
		}
		i = params[i][to_out].prev;
		to_out = (t_bool)((to_out + 1) % 2);
	}
}
