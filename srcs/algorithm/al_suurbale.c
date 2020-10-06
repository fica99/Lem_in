/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_suurbale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 18:23:59 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/06 15:18:06 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "lem_in.h"

void			al_del_paths(t_paths **paths)
{
	size_t		i;

	i = 0;
	while (i < (*paths)->nb_paths)
	{
		al_del_edges(&(((*paths)->paths)[i].edges));
		++i;
	}
	ft_memdel((void**)&(*paths)->paths);
	ft_memdel((void**)paths);
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
		new_search = (t_search){finded->to, True, finded->from, True, 0, False};
		while ((new_finded = al_get_edge(edges, &new_search)))
			ft_memdel((void**)&new_finded);
		ft_memdel((void**)&finded);
	}
}

static void		al_update_paths(t_paths *paths, t_edge **edges, size_t start,
																size_t end)
{
	size_t		cur_node;
	size_t		i;
	t_edge		*finded;
	t_search	search;

	i = 0;
	while (i < paths->nb_paths)
	{
		cur_node = start;
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

t_paths			*al_suurbale(t_graph *graph)
{
	int			path[graph->nb_nodes];
	int			dist[graph->nb_nodes];
	t_paths		*paths;
	t_edge		*edges;
	size_t		nb_paths;

	paths = (t_paths *)ft_xmalloc(sizeof(t_paths));
	edges = NULL;
	nb_paths = ft_min(al_count_edges(graph->nodes[graph->graph_end]->edges_out),
					al_count_edges(graph->nodes[graph->graph_start]->edges_out));
	while (nb_paths)
	{
		al_bellman_ford(graph, dist, path);
		if (dist[graph->graph_end] == INT_MAX)
			break ;
		++paths->nb_paths;
		al_update_graph(graph, path, &edges);
		--nb_paths;
	}
	paths->paths = ft_xmalloc(sizeof(t_path) * (paths->nb_paths));
	al_del_reverse_edges(&edges);
	al_update_paths(paths, &edges, graph->graph_start, graph->graph_end);
	al_sort_paths(paths);
	lemin_edge_clean(&edges);
	return (paths);
}
