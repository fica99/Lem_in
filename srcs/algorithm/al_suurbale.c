/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_suurbale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 18:23:59 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/21 16:08:54 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static void	al_add_path(t_paths *paths)
{
	size_t	prev_malloc_nb;

	if (++(paths->nb_paths) >= paths->malloc_nb_paths * (2 / 3))
	{
		prev_malloc_nb = paths->malloc_nb_paths;
		if (prev_malloc_nb)
			paths->malloc_nb_paths *= 2;
		else
			paths->malloc_nb_paths = paths->nb_paths;
		paths->paths = (t_edge**)ft_memrealloc_array((void***)&(paths->paths),
			prev_malloc_nb * sizeof(t_edge*),
							paths->malloc_nb_paths * sizeof(t_edge*));
	}
}

t_paths		*al_suurbale(t_graph *graph)
{
	int		path[graph->nb_nodes];
	int		dist[graph->nb_nodes];
	t_paths	*paths;

	paths = ft_xmalloc(sizeof(t_paths));
	ft_bzero((void*)paths, sizeof(t_paths));
	while (True)
	{
		al_bellman_ford(graph, dist, path);
		if (dist[graph->graph_end] == INT_MAX)
			break ;
		al_add_path(paths);
		al_update_graph(graph, path, paths);
	}
	// concatenate paths
	return (paths);
}
