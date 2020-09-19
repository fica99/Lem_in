/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 21:24:50 by aashara           #+#    #+#             */
/*   Updated: 2020/09/19 20:55:15 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include <limits.h>
# include "graph.h"
# include "libft.h"

typedef struct		s_path
{
	t_node			*nodes;
	struct s_path	*next;
}					t_path;

/*
**		al_bellman_ford.c
*/
void	al_bellman_ford(t_graph *graph, int *dist, int *path);
/*
**		al_suurbale.c
*/
void	al_suurbale(t_graph *graph);
#endif
