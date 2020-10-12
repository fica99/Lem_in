/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_edges_proc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:01:52 by sschmele          #+#    #+#             */
/*   Updated: 2020/10/12 14:20:06 by sschmele         ###   ########.fr       */
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

int				lemin_check_edge_out(t_edge *begin_edge)
{
	t_edge		*run;
	t_edge		*run_delete;

	run = begin_edge;
	while (run->next)
	{
		if ((int)run->next->from < 0 || (int)run->next->to < 0)
		{
			while (run->next)
			{
				run_delete = run->next->next;
				free(run->next);
				run->next = run_delete;
			}
			run->next = NULL;
		}
		run = run->next;
	}
	if (run == begin_edge)
	{
		free(begin_edge);
		return (1);
	}
	return (0);
}

int				lemin_check_edge_in(t_edge *begin_edge, size_t index)
{
	t_edge		*run;

	run = begin_edge;
	while (run)
	{
		if ((int)run->from < 0 || (int)run->to < 0)
		{
			run->from = index;
			run->to = index;
		}
		run = run->next;
	}
	return (0);
}