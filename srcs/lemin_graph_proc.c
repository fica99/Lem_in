/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_graph_proc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 14:29:17 by sschmele          #+#    #+#             */
/*   Updated: 2020/10/05 18:11:56 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "graph.h"

t_graph			lemin_graph_init(void)
{
	t_graph			farm;

	farm.graph_start = -1;
	farm.graph_end = -1;
	farm.nb_nodes = -1;
	farm.nodes_len = 0;
	farm.nodes = NULL;
	return (farm);
}

/*
** @mode = 0 means that we get graph:
**     t_graph farm;
**     farm = NULL;
**     lemin_graph_methods(&farm, 0);
** @mode = 1 means that we save graph:
**	   t_graph farm;
**     farm = lemin_graph_init();
**     lemin_graph_methods(&farm, 1);
** @mode = -1 means that we clear graph
** saved in static
*/

int				lemin_graph_methods(t_graph *new_farm, int mode)
{
	static t_graph main_farm;

	if (new_farm != NULL && mode == 1)
		main_farm = *new_farm;
	else if (mode == 0)
		*new_farm = main_farm;
	else
		lemin_graph_clean(main_farm);
	return (0);
}

void			lemin_graph_clean(t_graph farm)
{
	lemin_nodesarray_clean(&farm.nodes, farm.nb_nodes);
	farm.graph_start = -1;
	farm.graph_end = -1;
	farm.nb_nodes = -1;
}

/*
** @mode = 0 means that we get ants sum:
**     int sum;
**     sum = lemin_antsum_methods(0, 0);
** @mode = 1 means that we save ants sum:
**	   int sum;
**     sum = n;
**     lemin_antsum_methods(n, 1);
** @mode = -1 means that we bzero value
** saved in static
*/

int				lemin_antsum_methods(int ants, int mode)
{
	static int		main_antssum;

	if (ants && mode == 1)
		main_antssum = ants;
	else if (!ants && mode == 0)
		return (main_antssum);
	else
		main_antssum = 0;
	return (0);
}
