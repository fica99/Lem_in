/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_first_filter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 20:01:11 by sschmele          #+#    #+#             */
/*   Updated: 2020/09/28 21:12:11 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "validator.h"

int			val_invalid_lines(char *map, int map_size)
{
	int		i;
	int		k;

	if (val_check_antsnum(map, map_size) == VAL_ERROR)
		return (VAL_ERROR);
	i = 0;
	while (map[i])
	{
		if (i > 0 && map[i - 1] == VAL_ENTER && map[i] == 'L')
		{
			val_errors(ERR_INVALID_LINE, map + i, VAL_ENTER, 0);
			k = val_find_delimiter(map, i);
			return (val_errors(ERR_INVALID_ROOMNAME, map + i, map[i + k], 0));
		}
		if (val_check_spaces(map, i) == VAL_ERROR)
			return (VAL_ERROR);
		if (map[i] == VAL_ENTER && map[i + 1] == VAL_ENTER)
			return (val_errors(ERR_EMPTY, NULL, 0, 0));
		if (val_invalid_startend(map, map_size, &i) == VAL_ERROR)
			return (VAL_ERROR);
		i++;
	}
	return (0);
}

int			val_check_antsnum(char *map, int map_size)
{
	int		i;
	
	i = 0;
	if (map[i] == VAL_SPACE)
	{
		val_errors(ERR_INVALID_LINE, map, VAL_ENTER, 0);
		val_errors(ERR_SPACE_START, NULL, 0, 0);
		return (val_errors(ERR_NOANTS, NULL, 0, 0));
	}
	if (map[i] == VAL_DASH || map[i] == '+')
		i++;
	while (map[i] && ft_isdigit(map[i]))
		i++;
	if (map[i] != VAL_ENTER && i < map_size)
	{
		val_errors(ERR_INVALID_LINE, map, VAL_ENTER, 0);
		val_pass_spaces(map, &i);
		if (map[i] == VAL_ENTER)
			val_errors(ERR_SPACE_END, NULL, 0, 0);
		return (val_errors(ERR_NOANTS, NULL, 0, 0));
	}
	else if (i == map_size)
		return (val_errors(ERR_NOROOMS, NULL, 0, 0));
	return (0);
}

int			val_invalid_startend(char *map, int map_size, int *i)
{
	int		j;
	int		len_tmp;
	char	*valid;

	j = *i;
	if (j > 0 && map[j] == VAL_HASH && map[j + 1] == VAL_HASH
			&& map[j - 1] == VAL_ENTER)
	{
		if (map[j + 2] && map[j + 2] == 's')
			valid = "##start";
		else if (map[j + 2] && map[j + 2] == 'e')
			valid = "##end";
		else
			return (val_errors(ERR_INVALID_LINE, map + j, VAL_ENTER, 0));
		len_tmp = ft_strlen(valid);
		if (!(j + len_tmp <= map_size &&
				ft_strncmp(map + j, valid, len_tmp) == 0 &&
				(map[j + len_tmp] == VAL_ENTER ||
				map[j + len_tmp] == VAL_SPACE || !map[j + len_tmp])))
			return (val_errors(ERR_INVALID_LINE, map + j, VAL_ENTER, 0));
		*i = j;
	}
	return (0);
}

int			val_check_spaces(char *map, int i)
{
	if (i > 0 && map[i - 1] == VAL_ENTER && map[i] == VAL_SPACE)
	{
		val_errors(ERR_INVALID_LINE, map + i, VAL_ENTER, 0);
		return (val_errors(ERR_SPACE_START, NULL, 0, 0));
	}
	if (i > 0 && map[i] == VAL_ENTER && map[i - 1] == VAL_SPACE)
	{
		i--;
		while (i > 0 && map[i] != VAL_ENTER)
			i--;
		if (!(map[i + 1] == VAL_HASH && map[i + 2] && map[i + 2] != VAL_HASH))
		{
			val_errors(ERR_INVALID_LINE, map + i + 1, VAL_ENTER, 0);
			return (val_errors(ERR_SPACE_END, NULL, 0, 0));
		}
	}
	if (map[i] == VAL_SPACE && !map[i + 1])
	{
		while (i > 0 && map[i] != VAL_ENTER)
			i--;
		val_errors(ERR_INVALID_LINE, map + i + 1, VAL_ENTER, 0);
		return (val_errors(ERR_SPACE_END, NULL, 0, 0));
	}
	return (0);
}
