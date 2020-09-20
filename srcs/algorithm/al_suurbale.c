/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_suurbale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 18:23:59 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/20 18:32:39 by aashara-         ###   ########.fr       */
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

static t_edge	*al_find_edge(t_node **nodes, size_t from, size_t to)
{
	t_edge	*finded;

	finded = nodes[from]->edges;
	while (finded != NULL)
	{
		if (finded->from == from && finded->to == to)
			break ;
		finded = finded->next;
	}
	return (finded);
}

static void		al_del_edge(t_graph *graph, size_t from, size_t to)
{
	t_edge	*finded;
	t_edge	*tmp;

	finded = graph->nodes[from]->edges;
	if (finded->from == from && finded->to == to)
	{
		graph->nodes[from]->edges = finded->next;
		ft_memdel(&finded);
		return ;
	}
	while (finded->next != NULL)
	{
		tmp = finded->next;
		if (tmp->from == from && tmp->to == to)
		{
			finded->next = tmp->next;
			ft_memdel(&tmp);
			return ;
		}
		finded = finded->next;
	}
}

static void		al_replace_edges(t_graph *graph, int *dist, int *path)
{
	size_t	i;
	t_edge	*finded;

	i = graph->graph_end;
	while (i != graph->graph_start)
	{
		finded = al_find_edge(graph->nb_nodes, i, path[i]);
		finded->weight = -1;
		al_del_edge(graph, path[i], i);
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
		al_replace_edges(graph, dist, path);
		
	}
}
