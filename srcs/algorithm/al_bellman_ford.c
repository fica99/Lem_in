/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_bellman_ford.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 21:25:15 by aashara           #+#    #+#             */
/*   Updated: 2020/10/08 18:14:41 by aashara-         ###   ########.fr       */
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

static t_bool	al_check_edges(t_edge *edges, t_bell_ford_params params[][2], t_bool is_changed, t_bool is_out)
{
	t_edge	*tmp;

	tmp = edges;
	while (tmp)
	{
		if (params[tmp->from][is_out].dist < INT_MAX)
		{
			if (params[tmp->to][(is_out + 1) % 2].dist > params[tmp->from][is_out].dist + tmp->weight)
			{
				params[tmp->to][(is_out + 1) % 2].dist = params[tmp->from][is_out].dist + tmp->weight;
				params[tmp->to][(is_out + 1) % 2].prev = tmp->from;
				is_changed = True;
			}
		}
		tmp = tmp->next;
	}
	return (is_changed);
}

static t_bool	al_update_dist(t_node **nodes, size_t nb_nodes,
											t_bell_ford_params params[][2])
{
	t_bool	is_changed;
	size_t	i;

	is_changed = False;
	i = 0;
	while (i < nb_nodes)
	{
		is_changed = al_check_edges(nodes[i]->edges_out, params, is_changed, True);
		is_changed = al_check_edges(nodes[i]->edges_in, params, is_changed, False);
		++i;
	}
	return (is_changed);
}

void			al_bellman_ford(t_graph *graph, t_bell_ford_params params[][2])
{
	size_t	i;

	al_init_params(params, graph->nb_nodes, graph->graph_start);
	i = 0;
	while (++i < graph->nb_nodes)
	{
		if (!al_update_dist(graph->nodes, graph->nb_nodes, params))
			break ;
	}
}
