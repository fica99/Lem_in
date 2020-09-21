/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 21:24:50 by aashara           #+#    #+#             */
/*   Updated: 2020/09/21 15:00:58 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include <limits.h>
# include "graph.h"
# include "libft.h"

typedef struct		s_paths
{
	size_t			nb_paths;
	size_t			malloc_nb_paths;
	t_edge			**paths;
}					t_paths;

/*
**		al_bellman_ford.c
*/
void	al_bellman_ford(t_graph *graph, int *dist, int *path);
/*
**		al_suurbale_update_graph.c
*/
t_edge	*al_add_edge(t_edge **edges, size_t from, size_t to,
															t_bool is_start);
void	al_update_graph(t_graph *graph, int *arr_nodes, t_paths *paths);
/*
**		al_suurbale.c
*/
t_paths	*al_suurbale(t_graph *graph);
#endif
