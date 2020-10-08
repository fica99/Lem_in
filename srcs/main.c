/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara <aashara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:58:48 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/09 02:29:09 by aashara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	lemin_del_paths(t_paths **paths)
{
	size_t		i;

	i = 0;
	while (i < (*paths)->nb_paths)
	{
		lemin_edge_clean(&(((*paths)->paths)[i].edges));
		++i;
	}
	ft_memdel((void**)&(*paths)->paths);
	ft_memdel((void**)paths);
}

static void		lemin_calc_number_ants(size_t nb_ants, t_paths *paths, size_t i, size_t ants[])
{
	size_t	j;
	size_t	cur_path;
	size_t	next_path;

	j = 0;
	while (j < i)
		ants[j++] = 0;
	cur_path = 0;
	while (nb_ants--)
	{
		next_path = (cur_path + 1) % i;
		if (ants[cur_path] + paths->paths[cur_path].nb_nodes <=
							ants[next_path] + paths->paths[next_path].nb_nodes)
		{
			++ants[cur_path];
			cur_path = 0;
		}
		else
		{
			++ants[next_path];
			cur_path = next_path;
		}
	}
}

static size_t	lemin_calc_nb_steps(size_t nb_ants, t_paths *paths, size_t i)
{
	size_t			nb_steps;
	size_t			ants[i + 1];
	size_t			max_path;
	size_t			j;

	lemin_calc_number_ants(nb_ants, paths, i, ants);
	j = 0;
	max_path = 0;
	nb_steps = ants[0];
	while (++j < i)
		if (paths->paths[j].nb_nodes > paths->paths[max_path].nb_nodes)
			max_path = j;
	return (nb_steps + paths->paths[max_path].nb_nodes);
}

static void		lemin_check_steps(int nb_ants, t_paths *paths)
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
	ft_printf("paths->nb_paths - %d, best_path - %d\n", paths->nb_paths, best_path);
	while (++i < paths->nb_paths)
		lemin_edge_clean(&paths->paths[i].edges);
	paths->nb_paths = best_path + 1;
}


static void	lemin_print(t_paths *paths, t_graph *graph, int nb_ants)
{
	if (paths->nb_paths == 0)
	{
		lemin_del_paths(&paths);
		val_errors(ERR_NOSOLUTION, NULL, 0, 0);
	}
	lemin_check_steps(nb_ants, paths);
	(paths->paths[0].nb_nodes != 1) ? lem_in_print_paths(paths, graph->nodes,
	nb_ants) : lem_in_print_all(graph->nodes[graph->graph_end]->name, nb_ants);
	lemin_del_paths(&paths);
	lemin_graph_methods(NULL, -1);
	lemin_antsum_methods(0, -1);
}

int			main(int argc, char **argv)
{
	int		answer;
	t_paths	*paths;
	t_graph	graph;
	int		nb_ants;

	answer = val_start_validation(argc, argv);
	if (answer == VAL_ERROR)
	{
		ft_putendl_fd("ERROR", STDERR_FILENO);
		lemin_graph_methods(NULL, -1);
		lemin_antsum_methods(0, -1);
		return (1);
	}
	else if (answer == STOP)
		return (0);
	lemin_graph_methods(&graph, 0);
	nb_ants = lemin_antsum_methods(0, 0);
	paths = al_suurbale(&graph);
	lemin_print(paths, &graph, nb_ants);
	return (0);
}

void		lemin_usage(void)
{
	ft_printf("%s works with standard input only\n", PROGRAM_NAME);
	ft_printf("%-10s %s [options] < file or %s [options]\n",
		"usage:", PROGRAM_NAME, PROGRAM_NAME);
	ft_printf("%11s%s [--help]\n", "", PROGRAM_NAME);
}
