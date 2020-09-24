/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_suurbale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 18:23:59 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/24 22:30:06 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
static void al_add_path(t_path **paths)
{
	t_path	*added;

	added = (t_path *)ft_xmalloc(sizeof(t_path));
	added->next = *paths;
	*paths = added;
}


t_path		*al_suurbale(t_graph *graph)
{
	int		path[graph->nb_nodes];
	int		dist[graph->nb_nodes];
	t_path	*paths;

	paths = NULL;
	while (True)
	{
		al_bellman_ford(graph, dist, path);
		if (dist[graph->graph_end] == INT_MAX)
			break ;
		al_add_path(&paths);
		al_update_graph(graph, path, paths);
	}
//add edges list, delete reverse edges
	return (paths);
}
