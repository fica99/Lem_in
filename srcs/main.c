/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:58:48 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/12 17:06:34 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	lemin_print(t_paths *paths, t_graph *graph, int nb_ants)
{
	int	answer;

	answer = 0;
	if (!paths || paths->nb_paths == 0)
		answer = val_errors(ERR_NOSOLUTION, NULL, 0, 0);
	else
	{
		(paths->paths[0].nb_nodes != 1) ?
			lem_in_print_paths(paths, graph->nodes, nb_ants) :
			lem_in_print_all(graph->nodes[graph->graph_end]->name, nb_ants);
	}
	al_del_paths(paths);
	ft_memdel((void**)&paths);
	lemin_graph_methods(NULL, -1);
	lemin_antsum_methods(0, -1);
	return (answer);
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
	paths = al_suurbale(&graph, nb_ants);
	answer = lemin_print(paths, &graph, nb_ants);
	if (answer == VAL_ERROR)
	{
		ft_putendl_fd("ERROR", STDERR_FILENO);
		return (1);
	}
	return (0);
}

void		lemin_usage(void)
{
	ft_printf("%s works with standard input only\n", PROGRAM_NAME);
	ft_printf("%-10s %s [options] < file or %s [options]\n",
		"usage:", PROGRAM_NAME, PROGRAM_NAME);
	ft_printf("%11s%s [--help]\n", "", PROGRAM_NAME);
}
