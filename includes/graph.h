/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara <aashara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 20:51:26 by aashara           #+#    #+#             */
/*   Updated: 2020/09/18 20:58:24 by aashara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# include <stdio.h>

typedef enum
{
	False = 0,
	True = 1,
}				t_bool;

typedef enum
{
	Start,
	Middle,
	End
}				t_node_type;

typedef struct	s_node
{
	char		*name;
	int			x;
	int			y;
	t_node_type	type;
	size_t		nb_in;
	size_t		nb_out;
}				t_node;

typedef struct	s_graph
{
	size_t		nb_nodes;
	size_t		nb_ribs;
	t_node		*nodes;
	size_t		graph_start;
	size_t		graph_end;
	char		**matrix;
}				t_graph;

#endif
