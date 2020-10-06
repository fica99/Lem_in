/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_print_paths.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 06:44:10 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/06 18:51:10 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		lem_in_init_len(t_paths *paths, int *len)
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

static t_bool	lem_in_print_path(t_path *path, t_node **nodes, int ant_nb)
{
	t_edge	*tmp;
	int		ant_tmp;
	t_bool	is_printed;

	tmp = path->edges;
	is_printed = False;
	while (tmp)
	{
		if (ant_nb > 0)
		{
			ft_printf("L%d-%s ", ant_nb, nodes[tmp->to]->name);
			is_printed = True;
		}
		ant_tmp = ant_nb;
		ant_nb = tmp->weight;
		tmp->weight = ant_tmp;
		tmp = tmp->next;
	}
	return (is_printed);
}

void			lem_in_print_paths(t_paths *paths, t_node **nodes, int nb_ants)
{
	size_t	cur_path;
	int		i;
	int		len[paths->nb_paths];
	t_bool	is_printed;
	t_bool	tmp;

	lem_in_init_len(paths, len);
	i = 0;
	while (True)
	{
		cur_path = 0;
		is_printed = False;
		while (cur_path < paths->nb_paths)
		{
			tmp = (((nb_ants - i) > len[cur_path]) ?
			lem_in_print_path(paths->paths + cur_path, nodes, ++i) :
			lem_in_print_path(paths->paths + cur_path, nodes, 0));
			if (!is_printed)
				is_printed = tmp;
			++cur_path;
		}
		if (is_printed == False)
			break ;
		ft_putchar('\n');
	}
}

void			lem_in_print_all(char *name, int nb_ants)
{
	int	i;

	i = 0;
	while (++i <= nb_ants)
		ft_printf("L%d-%s ", i, name);
	ft_putchar('\n');
}
