/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_suurbale_update_graph.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:05:00 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/23 22:16:56 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static t_edge	*al_get_edge(t_node **nodes, size_t from, size_t to,
																t_bool is_in)
{
	t_edge	*finded;
	t_edge	*tmp;

	finded = (is_in == True ? nodes[from]->edges_in : nodes[from]->edges_out);
	if (finded->from == from && finded->to == to)
	{
		if (is_in == True)
			nodes[from]->edges_in = finded->next;
		else
			nodes[from]->edges_out = finded->next;
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

void		al_add_edge(t_node **nodes, t_edge *edge, size_t from, t_bool is_in)
{
	t_edge	*tmp;

	tmp = (is_in == True ? nodes[from]->edges_in : nodes[from]->edges_out);
	edge->next = tmp;
	if (is_in == True)
		nodes[from]->edges_in = edge;
	else
		nodes[from]->edges_out = edge;
}

void			al_reverse_edges(t_node **nodes, size_t from, size_t to)
{
	t_edge	*edge;

	edge = al_get_edge(nodes, to, from, False);
	ft_memdel((void**)&edge);
	edge = al_get_edge(nodes, from, to, True);
	ft_memdel((void**)&edge);
	edge = al_get_edge(nodes, from, to, False);
	edge->next = NULL;
	edge->weight = -1;
	edge->from = to;
	edge->to = from;
	al_add_edge(nodes, edge, to, True);
	edge = al_get_edge(nodes, to, from, True);
	edge->next = NULL;
	edge->weight = -1;
	edge->from = to;
	edge->to = from;
	al_add_edge(nodes, edge, from, False);
}


void			al_update_graph(t_graph *graph, int *arr_nodes, t_path *paths)
{
	size_t	i;

	(void)paths;
	i = graph->graph_end;
	while (i != graph->graph_start)
	{
		al_reverse_edges(graph->nodes, arr_nodes[i], i);
		i = arr_nodes[i];
	}

}
