/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_find_optimal_paths.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 16:16:48 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/09 17:06:40 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		lemin_calc_number_ants(size_t nb_ants, t_paths *paths,
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

static size_t	lemin_calc_nb_steps(size_t nb_ants, t_paths *paths, size_t i)
{
	size_t			nb_steps;
	size_t			ants[i];
	size_t			max_path;
	size_t			j;

	lemin_calc_number_ants(nb_ants, paths, i, ants);
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

void			lemin_check_steps(int nb_ants, t_paths *paths)
{
	size_t			nb_steps[paths->nb_paths];
	size_t			i;
	size_t			best_path;

	if (paths->paths[0].nb_nodes == 1)
		nb_steps[0] = 1;
	else
		nb_steps[0] = nb_ants + paths->paths[0].nb_nodes - 1;
	i = 0;
	while (++i < paths->nb_paths)
		nb_steps[i] = lemin_calc_nb_steps(nb_ants, paths, i + 1);
	best_path = 0;
	i = 0;
	while (++i < paths->nb_paths)
		if (nb_steps[best_path] > nb_steps[i])
			best_path = i;
	i = best_path;
	while (++i < paths->nb_paths)
		lemin_edge_clean(&paths->paths[i].edges);
	paths->nb_paths = best_path + 1;
}
