/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:12:22 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/25 11:12:23 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "validator.h"
# include "algorithm.h"

# define VAL_ERROR -1

/*
**		lemin_print_paths.c
*/
void	lem_in_print_paths(t_paths *paths, t_node **nodes, int nb_ants);
#endif
