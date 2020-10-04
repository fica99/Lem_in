/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_nodes_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 14:51:10 by sschmele          #+#    #+#             */
/*   Updated: 2020/10/04 20:31:34 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "graph.h"

void			lemin_nodesarray_print(t_node **nodes,
					size_t nb_nodes)
{
	size_t		i;
	char		*delim;

	ft_printf("\nThere are %d nodes\n", nb_nodes);
	if (!nodes || !nodes[0] || nb_nodes == 0)
	{
		ft_printf("No information can be given\n");
		return ;
	}
	i = 0;
	delim = "---------------------------------------";
	while (i < nb_nodes && nodes[i])
	{
		ft_printf("\nindex %d\n", (int)i);
		ft_printf("%s\n", delim);
		lemin_print_onenode(nodes[i]);
		i++;
	}
}

void			lemin_print_onenode(t_node *node)
{
	t_edge		*edge;
	t_edge		*run;

	ft_printf("room_name = %s\n", node->name);
	ft_printf("coordinates: x = %d, y = %d\n",
		node->x, node->y);
	ft_printf("edges:\n");
	edge = node->edges_in;
	run = edge;
	while (run)
	{
		if (run != edge)
			ft_printf("\nnext edge\n");
		ft_printf("from index: %d, to index: %d\n",
			(int)run->from, (int)run->to);
		ft_printf("weight: %d\n", (int)run->weight);
		run = run->next;
	}
}