/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 21:24:50 by aashara           #+#    #+#             */
/*   Updated: 2020/09/23 21:58:27 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include <limits.h>
# include "graph.h"
# include "libft.h"

typedef struct		s_path
{
	size_t			nb_nodes;
	int				*path;
	struct s_path	*next;
}					t_path;

/*
**		al_bellman_ford.c
*/
void	al_bellman_ford(t_graph *graph, int *dist, int *path);
/*
**		al_suurbale_update_graph.c
*/
void	al_add_edge(t_node **nodes, t_edge *edge, size_t from, t_bool is_in);
void	al_update_graph(t_graph *graph, int *arr_nodes, t_path *paths);
/*
**		al_suurbale.c
*/
t_path	*al_suurbale(t_graph *graph);
#endif
