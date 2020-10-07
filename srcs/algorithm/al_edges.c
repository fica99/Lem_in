/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_edges.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 02:19:35 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/07 20:10:26 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static t_bool	al_check_finded(t_edge *edge, t_search *search)
{
	if (!edge || !search)
		return (False);
	if (search->is_from)
		if (edge->from != search->from)
			return (False);
	if (search->is_to)
		if (edge->to != search->to)
			return (False);
	if (search->is_weight)
		if (edge->weight != search->weight)
			return (False);
	return (True);
}

t_edge			*al_get_edge(t_edge **edges, t_search *search)
{
	t_edge	*finded;
	t_edge	*tmp;

	finded = *edges;
	if (!finded)
		return (NULL);
	if (al_check_finded(finded, search))
	{
		*edges = finded->next;
		return (finded);
	}
	while (finded && finded->next)
	{
		tmp = finded->next;
		if (tmp && al_check_finded(tmp, search))
		{
			finded->next = tmp->next;
			return (tmp);
		}
		finded = finded->next;
	}
	return (NULL);
}

void			al_add_edge(t_edge **edges, t_edge *edge, t_bool is_end)
{
	t_edge	*tmp;

	if (!is_end)
	{
		edge->next = *edges;
		*edges = edge;
	}
	else
	{
		tmp = *edges;
		if (!tmp)
			*edges = edge;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = edge;
		}
	}
}

void			al_del_edges(t_edge **edges)
{
	t_edge	*tmp;
	t_edge	*next;

	tmp = *edges;
	*edges = NULL;
	while (tmp)
	{
		next = tmp->next;
		ft_memdel((void**)&tmp);
		tmp = next;
	}
}

size_t			al_count_edges(t_edge *edges)
{
	size_t	count;

	count = 0;
	while (edges)
	{
		edges = edges->next;
		++count;
	}
	return (count);
}
