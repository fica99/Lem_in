/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_suurbale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 18:23:59 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/09 17:05:15 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "lem_in.h"

static void		al_sort_paths(t_paths *paths)
{
	size_t		i;
	t_path		tmp;

	if (paths->nb_paths < 2)
		return ;
	i = 0;
	while (i < paths->nb_paths - 1)
	{
		if (paths->paths[i].nb_nodes > paths->paths[i + 1].nb_nodes)
		{
			tmp = paths->paths[i];
			paths->paths[i] = paths->paths[i + 1];
			paths->paths[i + 1] = tmp;
			if (i)
				--i;
			continue ;
		}
		++i;
	}
}

static void		al_del_reverse_edges(t_edge **edges)
{
	t_edge		*finded;
	t_edge		*new_finded;
	t_search	search;
	t_search	new_search;

	search = (t_search){0, False, 0, False, -1, True};
	while ((finded = al_get_edge(edges, &search)))
	{
		new_search = (t_search){finded->from, True, finded->to,
															True, 0, False};
		while ((new_finded = al_get_edge(edges, &new_search)))
			ft_memdel((void**)&new_finded);
		ft_memdel((void**)&finded);
	}
}

static void		al_update_paths(t_paths *paths, t_edge **edges,
											size_t start, size_t end)
{
	size_t		cur_node;
	size_t		i;
	t_edge		*finded;
	t_search	search;

	i = 0;
	while (i < paths->nb_paths)
	{
		cur_node = start;
		paths->paths[i].nb_nodes = 0;
		while (cur_node != end)
		{
			search = (t_search){cur_node, True, 0, False, 0, False};
			finded = al_get_edge(edges, &search);
			finded->weight = 0;
			finded->next = NULL;
			al_add_edge(&paths->paths[i].edges, finded, True);
			++(paths->paths[i].nb_nodes);
			cur_node = finded->to;
		}
		++i;
	}
}

t_paths			*al_suurbale(t_graph *graph)
{
	t_bell_ford_params	params[graph->nb_nodes][2];
	t_paths				*paths;
	t_edge				*edges;
	size_t				nb_paths;

	edges = NULL;
	nb_paths = ft_min(al_count_edges(graph->nodes[graph->graph_end]->edges_out),
				al_count_edges(graph->nodes[graph->graph_start]->edges_out));
	paths = (t_paths *)ft_xmalloc(sizeof(t_paths));
	paths->paths = ft_xmalloc(sizeof(t_path) * (nb_paths));
	while (nb_paths)
	{
		al_bellman_ford(graph, params);
		if (params[graph->graph_end][1].dist == INT_MAX)
			break ;
		++paths->nb_paths;
		al_update_graph(graph, params, &edges);
		--nb_paths;
	}
	al_del_reverse_edges(&edges);
	al_update_paths(paths, &edges, graph->graph_start, graph->graph_end);
	al_sort_paths(paths);
	lemin_edge_clean(&edges);
	return (paths);
}
