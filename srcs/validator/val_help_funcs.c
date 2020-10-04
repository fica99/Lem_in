/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_help_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 21:08:20 by sschmele          #+#    #+#             */
/*   Updated: 2020/10/05 00:28:18 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "validator.h"

int			val_pass_spaces(char *map, int *i)
{
	if (map[*i] == VAL_SPACE)
		while (map[*i] && map[*i] == VAL_SPACE)
			(*i)++;
	return (0);
}

int			val_find_delimiter(char *map, int i)
{
	int		k;

	k = 0;
	while (map[i + k] && val_isdelimiter(map, i + k) == 0)
		k++;
	return (k);
}

int			val_isdelimiter(char *map, int i)
{
	if (map[i] && (map[i] == VAL_ENTER ||
			map[i] == VAL_SPACE ||
			(i > 0 && map[i] == VAL_DASH &&
			(!(map[i - 1] == VAL_ENTER || map[i - 1] == VAL_SPACE)) &&
			(!(map[i + 1] && map[i + 1] == VAL_ENTER &&
			map[i + 1] == VAL_SPACE)))))
		return (1);
	return (0);
}

int			val_pass_comments(char *map, int *i)
{
	int		j;
	
	j = *i;
	if (j > 0 && map[j] == VAL_HASH && map[j + 1] &&
			map[j + 1] != VAL_HASH &&
			map[j - 1] == VAL_ENTER)
	{
		while (map[j] && map[j] != VAL_ENTER)
			j++;
		j++;
		*i = j;
	}
	return (0);
}