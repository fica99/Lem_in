/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_suurbale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 18:23:59 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/23 21:50:28 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

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
		al_update_graph(graph, path, paths);
	}
	return (paths);
}
