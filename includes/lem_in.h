#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# include "libft.h"
# include "graph.h"
# include "validator.h"
# include "algorithm.h"

# define STOP -21

# define PROGRAM_NAME "./lem-in"
# define OPTIONS_NUM 2
# define PROGRAM_OPTIONS ""
# define HELP_OPTION 0x10000
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define SIZET_MAX sizeof(size_t)

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

/*
** File lemin_edges_proc.c
*/

t_edge	*lemin_edge_init(void);
void	lemin_edge_clean(t_edge **begin_edge);

#endif
