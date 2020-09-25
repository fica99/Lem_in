/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_print_paths.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 06:44:10 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/25 11:00:38 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	lem_in_init_len(t_paths *paths, int *len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < paths->nb_paths)
	{
		len[i] = 0;
		j = 0;
		while (j < i)
			len[i] += (paths->paths[i].nb_nodes - paths->paths[j++].nb_nodes);
		++i;
	}
}

static void	lem_in_print_path(t_path *path, t_node **nodes, int ant_nb)
{
	t_edge	*tmp;
	int		ant_tmp;

	tmp = path->edges;
	while (tmp)
	{
		if (ant_nb)
			ft_printf("L%d-%s ", ant_nb, nodes[tmp->to]->name);
		ant_tmp = ant_nb;
		ant_nb = tmp->weight;
		tmp->weight = ant_tmp;
		tmp = tmp->next;
	}
}

void		lem_in_print_paths(t_paths *paths, t_node **nodes, int nb_ants)
{
	size_t	cur_path;
	int		i;
	int		len[paths->nb_paths];

	//check no path from start to end
	lem_in_init_len(paths, len);
	i = 0;
	while (i < nb_ants)
	{
		cur_path = 0;
		while (cur_path < paths->nb_paths)
		{
			if ((nb_ants - i) > len[cur_path])
				lem_in_print_path(paths->paths + cur_path, nodes, ++i);
			else
				lem_in_print_path(paths->paths + cur_path, nodes, 0);
			++cur_path;
		}
		ft_putchar('\n');
	}
}
