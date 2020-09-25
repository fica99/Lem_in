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

t_node	*lemin_node_init(void);
void	lemin_node_clean(t_node **node);
t_edge	*lemin_edge_init(void);
void	lemin_edge_clean(t_edge **begin_edge);
void	lemin_nodesarray_clean(t_node ***nodes, size_t nb_nodes);

/*
** File lemin_graph_proc.c
*/

void	lemin_graph_init(void);
t_graph	lemin_get_graph(void);
int		lemin_save_graphints(size_t value, char flag);
int		lemin_save_graph_nodes(t_node **value);
void	lemin_graph_clean(void);

#endif
