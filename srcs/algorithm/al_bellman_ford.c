/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_bellman_ford.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara <aashara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 21:25:15 by aashara           #+#    #+#             */
/*   Updated: 2020/10/08 20:15:14 by aashara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static void		al_init_params(t_bell_ford_params params[][2],
										size_t nb_nodes, size_t graph_start)
{
	size_t	i;

	i = 0;
	while (i < nb_nodes)
	{
		params[i][0].dist = (i == graph_start ? 0 : INT_MAX);
		params[i][0].prev = -1;
		params[i][1].dist = (i == graph_start ? 0 : INT_MAX);
		params[i][1].prev = -1;
		++i;
	}
}

static t_bool	al_check_edges(t_edge *edges, t_bell_ford_params params[][2],
												t_bool is_changed, t_bool is_out)
{
	t_edge	*tmp;

	tmp = edges;
	while (tmp)
	{
		if (params[tmp->from][is_out].dist < INT_MAX)
		{
			if (params[tmp->to][(is_out + 1) % 2].dist >
								params[tmp->from][is_out].dist + tmp->weight)
			{
				params[tmp->to][(is_out + 1) % 2].dist =
								params[tmp->from][is_out].dist + tmp->weight;
				params[tmp->to][(is_out + 1) % 2].prev = tmp->from;
				is_changed = True;
			}
		}
		tmp = tmp->next;
	}
	return (is_changed);
}

static t_bool	al_update_dist(t_graph *graph, t_bell_ford_params params[][2])
{
	t_bool	is_changed;
	size_t	i;
	size_t	nb_nodes;
	t_node	**nodes;

	is_changed = False;
	i = 0;
	nb_nodes = graph->nb_nodes;
	nodes = graph->nodes;
	is_changed = al_check_edges(nodes[graph->graph_start]->edges_out, params, is_changed, True);
	is_changed = al_check_edges(nodes[graph->graph_start]->edges_in, params, is_changed, False);
	while (i < nb_nodes)
	{
		if (i != graph->graph_start && i != graph->graph_start)
		{
			is_changed = al_check_edges(nodes[i]->edges_out, params, is_changed, True);
			is_changed = al_check_edges(nodes[i]->edges_in, params, is_changed, False);
		}
		++i;
	}
	is_changed = al_check_edges(nodes[graph->graph_end]->edges_out, params, is_changed, True);
	is_changed = al_check_edges(nodes[graph->graph_end]->edges_in, params, is_changed, False);
	return (is_changed);
}

void			al_bellman_ford(t_graph *graph, t_bell_ford_params params[][2])
{
	size_t	i;

	al_init_params(params, graph->nb_nodes, graph->graph_start);
	i = 0;
	while (++i < graph->nb_nodes)
	{
		if (!al_update_dist(graph, params))
			break ;
	}
}
