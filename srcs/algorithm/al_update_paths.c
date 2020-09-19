/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_update_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 18:07:56 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/19 18:17:03 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static void	al_update_matrix(t_graph *graph, int *prev)
{
	size_t	i;

	i = graph->graph_start;
	while (prev[i] != -1)
	{
		graph->matrix[i][prev[i]] = -1;
		graph->matrix[prev[i]][i] = 0;
		i = prev[i];
	}
}
