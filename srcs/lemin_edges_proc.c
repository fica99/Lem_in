/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_edges_proc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:01:52 by sschmele          #+#    #+#             */
/*   Updated: 2020/10/12 13:42:46 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "graph.h"

t_edge			*lemin_edge_init(void)
{
	t_edge		*new_edge;

	new_edge = (t_edge*)ft_xmalloc(sizeof(t_edge));
	new_edge->from = -1;
	new_edge->to = -1;
	new_edge->weight = 1;
	new_edge->next = NULL;
	return (new_edge);
}

void			lemin_edge_clean(t_edge **begin_edge)
{
	t_edge		*runner;

	if (!(begin_edge) || !(*begin_edge))
		return ;
	while (*begin_edge)
	{
		runner = (*begin_edge)->next;
		free((*begin_edge));
		*begin_edge = runner;
	}
	*begin_edge = NULL;
}

int				lemin_check_edge(t_edge *begin_edge)
{
	t_edge		*run;

	run = begin_edge;
	while (run)
	{
		if ((int)run->from < 0 || (int)run->to < 0)
			return (1);
		run = run->next;
	}
	return (0);
}