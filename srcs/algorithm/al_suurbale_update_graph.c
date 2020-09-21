/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_suurbale_update_graph.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:05:00 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/21 15:58:04 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

t_edge	*al_add_edge(t_edge **edges, size_t from, size_t to,
															t_bool is_start)
{
	t_edge	*tmp;
	t_edge	*new;

	new = (t_edge *)ft_xmalloc(sizeof(t_edge));
	new->from = from;
	new->to = to;
	new->next = NULL;
	if (is_start)
	{
		new->next = *edges;
		*edges = new;
	}
	else
	{
		tmp = *edges;
		if (tmp)
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
		else
			*edges = new;
	}
	return (new);
}

static void		al_update_weight(t_node **nodes, size_t from, size_t to, int weight)
{
	t_edge	*finded;

	finded = nodes[from]->edges;
	while (finded != NULL)
	{
		if (finded->from == from && finded->to == to)
		{
			finded->weight = weight;
			return ;
		}
		finded = finded->next;
	}
	finded = al_add_edge(&(nodes[from]->edges), from, to, True);
	finded->weight = weight;
}

static t_edge	*al_del_edge(t_graph *graph, size_t from, size_t to)
{
	t_edge	*finded;
	t_edge	*tmp;

	finded = graph->nodes[from]->edges;
	if (finded->from == from && finded->to == to)
	{
		graph->nodes[from]->edges = finded->next;
		return (finded);
	}
	while (finded->next != NULL)
	{
		tmp = finded->next;
		if (tmp->from == from && tmp->to == to)
		{
			finded->next = tmp->next;
			return (tmp);
		}
		finded = finded->next;
	}
	return (NULL);
}

void			al_update_graph(t_graph *graph, int *arr_nodes, t_paths *paths)
{
	size_t	i;
	t_edge	*edge;

	i = graph->graph_end;
	while (i != graph->graph_start)
	{
		edge = al_del_edge(graph, arr_nodes[i], i);
		edge->next = paths->paths[paths->nb_paths - 1];
		paths->paths[paths->nb_paths - 1] = edge;
		al_update_weight(graph->nodes, i, arr_nodes[i], -1);
		// if (path[i] != graph->graph_start)
		// 	al_divide_node(graph, path[i]);
		i = arr_nodes[i];
	}

}
