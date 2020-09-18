/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_bellman_ford.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara <aashara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 21:25:15 by aashara           #+#    #+#             */
/*   Updated: 2020/09/18 22:21:03 by aashara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static void		al_init_dist(int *dist, size_t src, size_t nb_nodes)
{
	size_t	i;

	i = 0;
	while (i < nb_nodes)
	{
		dist[i] = (i == src ? 0 : INT_MAX);
		++i;
	}
}

static void 	al_init_prev(int *prev, size_t nb_nodes)
{
	size_t	i;

	i = 0;
	while (i < nb_nodes)
		prev[i++] = -1;
}

static t_bool	al_update_dist(char **matrix, size_t nb_nodes, int *dist,
																	int *prev)
{
	size_t	i;
	size_t	j;
	t_bool	is_changed;

	is_changed = False;
	i = 0;
	while (i < nb_nodes)
	{
		j = 0;
		while (j < nb_nodes)
		{
			if (dist[j] < INT_MAX)
			{
				if (dist[i] < dist[j] + matrix[i][j])
				{
					dist[i] = dist[j] + matrix[i][j];
					prev[i] = j;
					is_changed = True;
				}
			}
			++j;
		}
		++i;
	}
	return (is_changed);
}

void			al_bellman_ford(t_graph *graph, int *dist, int *prev)
{
	size_t	i;
	t_bool	is_changed;

	al_init_prev(prev, graph->nb_nodes);
	al_init_dist(dist, graph->graph_start, graph->nb_nodes);
	i = 0;
	while (i < graph->nb_nodes)
	{
		if (!al_update_dist(graph->matrix, graph->nb_nodes, dist, prev))
			break ;
		++i;
	}
}
