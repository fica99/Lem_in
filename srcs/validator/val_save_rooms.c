/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_save_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 21:15:08 by sschmele          #+#    #+#             */
/*   Updated: 2020/09/28 21:55:22 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "validator.h"

//проверка данных, ошибки: нет второй координаты
//такая комната уже существует, такая координата уже используется

int			val_check_roomdraft(char name[VAL_MAXROOMNAME],
				char coord[2][VAL_MAXROOMCOORD], t_graph *farm, int flag)
{
	printf("name = %s\n", name);
	printf("x = %s\n", coord[0]);
	printf("y = %s\n", coord[1]);
	// t_graph	ptr_farm;

	// ptr_farm = *farm;
	// ptr_farm.nodes
	// val_save_room(name, coord, farm, flag);
	return (0);
}

int			val_save_room(char name[VAL_MAXROOMNAME],
				char coord[2][VAL_MAXROOMCOORD], t_graph *farm, int flag)
{
	return (0);
}