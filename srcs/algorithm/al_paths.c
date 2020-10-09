/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_paths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:40:51 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/09 22:22:26 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "lem_in.h"

static void		al_calc_number_ants(int nb_ants, t_paths *paths,
													size_t i, size_t ants[])
{
	size_t	j;
	size_t	cur_path;
	size_t	next_path;
	size_t	on_cur_path;
	size_t	on_next_path;

	j = 0;
	while (j < i)
		ants[j++] = 0;
	cur_path = 0;
	while (nb_ants--)
	{
		next_path = (cur_path + 1) % i;
		on_cur_path = ants[cur_path] + paths->paths[cur_path].nb_nodes;
		on_next_path = ants[next_path] + paths->paths[next_path].nb_nodes;
		if (on_cur_path > on_next_path)
			cur_path = next_path;
		else if (on_cur_path < on_next_path)
			cur_path = 0;
		++ants[cur_path];
	}
}

size_t			al_calc_nb_steps(int nb_ants, t_paths *paths, size_t i)
{
	size_t			nb_steps;
	size_t			ants[i];
	size_t			max_path;
	size_t			j;

	al_calc_number_ants(nb_ants, paths, i, ants);
	j = 0;
	max_path = 0;
	nb_steps = ants[0];
	while (++j < i)
	{
		if (paths->paths[j].nb_nodes + ants[j] >
									paths->paths[max_path].nb_nodes + nb_steps)
		{
			max_path = j;
			nb_steps = ants[j];
		}
	}
	return (nb_steps + paths->paths[max_path].nb_nodes);
}

void			al_del_paths(t_paths *paths)
{
	size_t		i;

	i = 0;
	while (i < paths->nb_paths)
	{
		lemin_edge_clean(&((paths->paths)[i].edges));
		++i;
	}
	ft_memdel((void**)&paths->paths);
}

void			al_copy_paths(t_paths *from, t_paths *to)
{
	size_t	i;
	t_edge	*tmp;
	t_edge	*copy;

	to->nb_paths = from->nb_paths;
	to->nb_steps = from->nb_steps;
	to->paths = ft_xmalloc(sizeof(t_path) * from->nb_paths);
	i = 0;
	while (i < from->nb_paths)
	{
		to->paths[i].nb_nodes = from->paths[i].nb_nodes;
		tmp = from->paths[i].edges;
		while (tmp)
		{
			copy = ft_xmalloc(sizeof(t_edge));
			copy->next = NULL;
			copy->from = tmp->from;
			copy->to = tmp->to;
			al_add_edge(&(to->paths[i].edges), copy, True);
			tmp = tmp->next;
		}
		++i;
	}
}

t_paths			*al_find_best_path(t_paths *paths, size_t nb_paths)
{
	size_t	i;
	size_t	best;
	t_paths	*res;

	i = 0;
	best = 0;
	while (i < nb_paths)
	{
		if (paths[best].nb_steps > paths[i].nb_steps)
			best = i;
		++i;
	}
	res = (t_paths *)ft_xmalloc(sizeof(t_paths));
	al_copy_paths(paths + best, res);
	i = 0;
	while (i < nb_paths)
	{
		al_del_paths(paths + i);
		++i;
	}
	ft_memdel((void **)&paths);
	return (res);
}
