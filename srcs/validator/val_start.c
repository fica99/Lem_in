/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 21:22:08 by sschmele          #+#    #+#             */
/*   Updated: 2020/10/19 18:18:47 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "validator.h"

int			val_start_validation(int argc, char **argv)
{
	int		answer;

	answer = 0;
	if (argc > 1)
		answer = val_check_options(argv);
	if (answer == VAL_ERROR || answer == STOP)
		return (answer);
	if (val_read_stdinput() == VAL_ERROR)
		return (VAL_ERROR);
	return (0);
}

int			val_read_stdinput(void)
{
	char	buf[STDIN_BUFFER];
	char	*map;
	int		map_size;
	int		answer;

	ft_bzero(buf, STDIN_BUFFER);
	map = (char*)ft_xmalloc(1);
	map_size = 0;
	while ((answer = read(STDIN_FILENO, buf, STDIN_BUFFER - 1)) > 0)
	{
		map = ft_strrejoin(map, buf);
		map_size += answer;
		ft_bzero(buf, STDIN_BUFFER);
	}
	if (answer < 0 || map_size == 0)
	{
		free(map);
		return (val_errors((map_size == 0 ? ERR_NOFARM :
			ERR_TERM), NULL, 0, 1));
	}
	write(STDOUT_FILENO, map, map_size);
	ft_putchar_fd('\n', STDOUT_FILENO);
	answer = val_check_map(map, map_size);
	free(map);
	return ((answer == VAL_ERROR) ? VAL_ERROR : 0);
}

int			val_check_map(char *map, int map_size)
{
	int		answer;

	if (map_size > 0 && map[map_size - 1] == VAL_ENTER)
	{
		map[map_size - 1] = '\0';
		map_size -= 1;
	}
	answer = val_invalid_lines(map, map_size);
	if (answer == VAL_ERROR)
		return (VAL_ERROR);
	answer = val_invalid_values(map, map_size);
	if (answer == VAL_ERROR)
		return (VAL_ERROR);
	return (0);
}

int			val_check_farm(t_graph *farm)
{
	t_graph		ptr_farm;
	t_search	search_nolink;
	size_t		i;
	t_edge		*finded;

	ptr_farm = *farm;
	i = 0;
	if (ptr_farm.graph_start == SIZE_MAX)
		return (val_errors(ERR_NOSTART, NULL, 0, 0));
	if (ptr_farm.graph_end == SIZE_MAX)
		return (val_errors(ERR_NOEND, NULL, 0, 0));
	if (ptr_farm.nb_nodes < 1 || ptr_farm.nb_nodes == SIZE_MAX)
		return (val_errors(ERR_NOROOMS, NULL, 0, 0));
	search_nolink = (t_search){SIZE_MAX, True, SIZE_MAX, True, 0, False};
	while (i < ptr_farm.nb_nodes && ptr_farm.nodes[i])
	{
		while ((finded = al_get_edge(&(ptr_farm.nodes[i]->edges_out),
				&search_nolink)))
			ft_memdel((void**)&finded);
		lemin_check_edge_in(ptr_farm.nodes[i]->edges_in, i);
		i++;
	}
	return (0);
}
