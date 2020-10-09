/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 21:24:50 by aashara           #+#    #+#             */
/*   Updated: 2020/10/09 16:21:00 by aashara-         ###   ########.fr       */
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
	t_edge			*edges;
}					t_path;

typedef struct		s_paths
{
	size_t			nb_paths;
	t_path			*paths;
}					t_paths;

typedef struct		s_search
{
	size_t			from;
	t_bool			is_from;
	size_t			to;
	t_bool			is_to;
	int				weight;
	t_bool			is_weight;
}					t_search;

typedef struct		s_bell_ford_params
{
	int				dist;
	int				prev;
}					t_bell_ford_params;

/*
**					al_bellman_ford.c
*/
void				al_bellman_ford(t_graph *graph,
							t_bell_ford_params params[][2]);
/*
**					al_edges.c
*/
t_edge				*al_get_edge(t_edge **edges, t_search *search);
void				al_add_edge(t_edge **edges, t_edge *edge, t_bool is_end);
size_t				al_count_edges(t_edge *edges);
/*
**					al_suurbale_update_graph.c
*/
void				al_update_graph(t_graph *graph,
							t_bell_ford_params params[][2], t_edge **edges);
/*
**					al_suurbale.c
*/
t_paths				*al_suurbale(t_graph *graph);
#endif
