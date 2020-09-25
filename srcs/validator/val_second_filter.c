/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_second_filter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 20:35:49 by sschmele          #+#    #+#             */
/*   Updated: 2020/09/25 21:57:33 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "validator.h"

int			val_invalid_values(char *map, int map_size)
{
	int		i;
	t_graph	farm;
	int		ants;

	ants = val_getants(map);
	if (ants == VAL_ERROR)
		return (VAL_ERROR);
	farm = lemin_graph_init();
	i = ft_strchri(map, VAL_ENTER);
	if (val_getrooms(map, map_size, &i) == VAL_ERROR)
		return (VAL_ERROR);
	return (0);
}

int			val_getants(char *map)
{
	int		ants;

	ants = ft_atoi(map);
	if (ants < 1 && (map[0] == '0' || map[0] == VAL_DASH))
		return (val_errors(ERR_NOANTS, NULL, 0, 0));
	else if (ants < 1)
		return (val_errors(ERR_EXTRAANTS, NULL, 0, 0));
	lemin_antsum_methods(ants, 1);
	return (ants);
}

int			val_getrooms(char *map, int map_size, int *i)
{
	int		j;
	
	j = *i;
	while (map[j])
	{
		if (j > 0 && map[j] == VAL_HASH && map[j + 1] &&
				map[j + 1]!= VAL_HASH &&
				map[j - 1] == VAL_ENTER)
			while (map[j] && map[j] != VAL_ENTER)
				j++;
		j++;
	}
	*i = j;
	return (0);
}