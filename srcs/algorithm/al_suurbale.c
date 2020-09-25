/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_suurbale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 18:23:59 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/25 03:53:07 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static void	al_del_reverse_edges(t_edge **edges)
{
	t_edge		*finded;
	t_edge		*new_finded;
	t_search	search;
	t_search	new_search;

	search = (t_search){0, False, 0, False, -1, True};
	while ((finded = al_get_edge(edges, &search)))
	{
		new_search = (t_search){finded->to, True, finded->from, True, 0, False};
		new_finded = al_get_edge(edges, &new_search);
		ft_memdel((void**)&new_finded);
		ft_memdel((void**)&finded);
	}
}

static void	al_update_paths(t_paths *paths, t_edge **edges, size_t start,
																size_t end)
{
	size_t	cur_node;
	size_t	i;

	i = 0;
	while (i < paths->nb_paths)
	{
		cur_node = start;
		// while (cur_node != end)
		// {

		// }
		++i;
	}
}

t_paths		*al_suurbale(t_graph *graph)
{
	int		path[graph->nb_nodes];
	int		dist[graph->nb_nodes];
	t_paths	*paths;
	t_edge	*edges;

	paths = (t_paths *)ft_xmalloc(sizeof(t_paths));
	edges = NULL;
	while (True)
	{
		al_bellman_ford(graph, dist, path);
		if (dist[graph->graph_end] == INT_MAX)
			break ;
		++paths->nb_paths;
		al_update_graph(graph, path, &edges);
	}
	al_del_reverse_edges(&edges);
	paths->paths = ft_xmalloc(sizeof(t_path) * (paths->nb_paths + 1));
	al_update_paths(paths, &edges, graph->graph_start, graph->graph_end);
	return (paths);
}
