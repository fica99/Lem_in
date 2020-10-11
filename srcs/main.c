/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:58:48 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/09 16:17:21 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

	// lemin_graph_methods(&graph, 1);
	// lemin_nodesarray_print(graph.nodes, graph.nb_nodes);
	// if ((int)graph.graph_start && (int)graph.graph_end)
	// 	ft_printf("\nstart index is %d, end index is %d\n",
	// 		(int)graph.graph_start, (int)graph.graph_end);
	// else
	// 	ft_printf("no start or end\n");

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
