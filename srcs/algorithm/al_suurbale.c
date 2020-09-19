/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_suurbale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 18:23:59 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/19 21:05:00 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

// static t_edge	*al_add_edge(t_edge *edges, int from, int to, int weight)
// {
// 	t_edge	*tmp;
// 	t_edge	*new;

// 	tmp = edges;
// 	while (tmp->next != NULL)
// 		tmp = tmp->next;
// 	new = (t_edge *)ft_xmalloc(sizeof(t_edge));
// 	new->next = NULL;
// 	new->a = from;
// 	new->b = to;
// 	new->weight = weight;
// 	tmp->next = new;
// 	return (new);
// }

// static void		al_update_weight(t_edge *edges, int from, int to, int weight)
// {
// 	t_edge	*tmp;

// 	tmp = edges;
// 	while (tmp != NULL)
// 	{
// 		if (tmp->a == from && tmp->b == to)
// 		{
// 			tmp->weight = weight;
// 			break;
// 		}
// 		tmp = tmp->next;
// 	}
// }

// static void		al_duplicate_node(t_edge *edges, int node_i, size_t added_node)
// {
// 	t_edge	*tmp;

// 	tmp = edges;
// 	while (tmp)
// 	{
// 		tmp = tmp->next;
// 	}
// }

static void		al_update_edges(t_graph *graph, int *dist, int *path)
{
	size_t	i;

	i = graph->graph_end;
	while (i != graph->graph_start)
	{

		i = path[i];
	}
}

void			al_suurbale(t_graph *graph)
{
	int		path[graph->nb_nodes];
	int		dist[graph->nb_nodes];

	while (True)
	{
		al_bellman_ford(graph, dist, path);
		if (dist[graph->graph_start] == INT_MAX)
			return;
		al_update_edges(graph, dist, path);
	}
}
