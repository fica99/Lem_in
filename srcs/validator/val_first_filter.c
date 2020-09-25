/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_first_filter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 20:01:11 by sschmele          #+#    #+#             */
/*   Updated: 2020/09/25 13:34:51 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "validator.h"

int			val_invalid_lines(char *map, int map_size)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if ((i == 0 && map[i] == 'L') ||
				(i > 0 && map[i - 1] == VAL_ENTER && map[i] == 'L'))
			return (val_errors(ERR_INVALID_VALUES, map + i, VAL_SPACE, 0));
		if (map[i] == VAL_ENTER && map[i + 1] == VAL_ENTER)
			return (val_errors(ERR_EMPTY, NULL, 0, 0));
		if (val_invalid_startend(map + i, map_size) == VAL_ERROR)
			return (VAL_ERROR);
		i++;
	}
	return (0);
}

int			val_invalid_startend(char *map, int map_size)
{
	int		i;
	int		len_tmp;
	char	*valid;

	i = 0;
	if (map[i] == VAL_HASH && map[i + 1] == VAL_HASH)
	{
		if (map[i + 2] && map[i + 2] == 's')
			valid = "##start";
		else if (map[i + 2] && map[i + 2] == 'e')
			valid = "##end";
		else
			return (val_errors(ERR_INVALID_LINE, map + i,
				VAL_ENTER, 0));
		len_tmp = ft_strlen(valid);
		if (!(i + len_tmp <= map_size &&
				ft_strncmp(map + i, valid, len_tmp) == 0 &&
				(map[i + len_tmp] == VAL_ENTER || !map[i + len_tmp])))
			return (val_errors(ERR_INVALID_LINE, map + i,
				VAL_ENTER, 0));
	}
	return (0);
}

int			val_invalid_values(char *map, int map_size)
{
	return (0);
}