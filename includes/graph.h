/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 20:51:26 by aashara           #+#    #+#             */
/*   Updated: 2020/09/25 11:25:03 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# include <stdio.h>

typedef enum
{
	True = 1,
	False = 0
}	t_bool;

typedef	struct		s_edge
{
	size_t			from;
	size_t			to;
	int				weight;
	struct s_edge	*next;
}					t_edge;

typedef struct		s_node
{
	char			*name;
	int				x;
	int				y;
	t_edge			*edges_in;
	t_edge			*edges_out;
}					t_node;

typedef struct		s_graph
{
	size_t			nb_nodes;
	t_node			**nodes;
	size_t			graph_start;
	size_t			graph_end;
}					t_graph;

#endif
