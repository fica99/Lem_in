/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:12:22 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/12 14:19:59 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "graph.h"
# include "validator.h"
# include "algorithm.h"

# define STOP -21

# define PROGRAM_NAME "./lem-in"
# define OPTIONS_NUM 2
# define PROGRAM_OPTIONS ""
# define HELP_OPTION 0x10000

/*
** File main.c
*/

void	lemin_usage(void);

/*
** File lemin_farm_proc.c
*/

int		lemin_get_antsnum(void);
void	lemin_save_antsnum(int ants);

/*
** File lemin_nodes_proc.c
*/

t_node	*lemin_node_init(char *name, int x, int y);
void	lemin_node_clean(t_node **node);
void	lemin_nodesarray_clean(t_node ***nodes, size_t nb_nodes);
t_node	**lemin_nodesarray_realloc(t_node **nodesarray,
			size_t nodes_size, size_t new_size);

/*
** File lemin_graph_proc.c
*/

t_graph	lemin_graph_init(void);
int		lemin_graph_methods(t_graph *new_farm, int mode);
void	lemin_graph_clean(t_graph farm);
int		lemin_antsum_methods(int ants, int mode);

/*
** File lemin_nodes_search.c
*/

size_t	lemin_search_name(t_node **nodes,
			size_t nb_nodes, char *new_name);
size_t	lemin_search_coord(t_node **nodes,
			size_t nb_nodes, int x, int y);

/*
** File lemin_nodes_print.c
*/

void	lemin_nodesarray_print(t_node **nodes,
			size_t nb_nodes);
void	lemin_print_onenode(t_node *node);
void	lemin_print_edge(t_edge *edge);

/*
** File lemin_edges_proc.c
*/

t_edge	*lemin_edge_init(void);
void	lemin_edge_clean(t_edge **begin_edge);
int		lemin_check_edge_out(t_edge *begin_edge);
int		lemin_check_edge_in(t_edge *begin_edge, size_t index);

/*
**		lemin_print_paths.c
*/
void	lem_in_print_paths(t_paths *paths, t_node **nodes, int nb_ants);
void	lem_in_print_all(char *name, int nb_ants);
/*
**		lemin_find_optimal_paths.c
*/
void	lemin_check_steps(int nb_ants, t_paths *paths);

#endif
