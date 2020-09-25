/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_farm_proc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:00:32 by sschmele          #+#    #+#             */
/*   Updated: 2020/09/25 15:06:07 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		g_ants_num;

int				lemin_get_antsnum(void)
{
	return (g_ants_num);
}

void			lemin_save_antsnum(int ants)
{
	g_ants_num = ants;
}