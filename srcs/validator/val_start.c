/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 21:22:08 by sschmele          #+#    #+#             */
/*   Updated: 2020/10/12 14:19:52 by sschmele         ###   ########.fr       */
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
	if (answer < 0)
		return (val_errors(ERR_TERM, NULL, 0, 1));
	if (map_size == 0)
		return (val_errors(ERR_NOFARM, NULL, 0, 0));
	write(STDOUT_FILENO, map, map_size);
	ft_putchar_fd('\n', STDOUT_FILENO);
	answer = val_check_map(map, map_size);
	free(map);
	map = NULL;
	return ((answer == VAL_ERROR) ? VAL_ERROR : 0);
}

int			val_check_map(char *map, int map_size)
{
	int		answer;

	if (map_size> 0 && map[map_size - 1] == VAL_ENTER)
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
	t_graph	ptr_farm;
	size_t	i;

	ptr_farm = *farm;
	i = 0;
	if ((int)ptr_farm.graph_start < 0)
		return (val_errors(ERR_NOSTART, NULL, 0, 0));
	if ((int)ptr_farm.graph_end < 0)
		return (val_errors(ERR_NOEND, NULL, 0, 0));
	if ((int)ptr_farm.nb_nodes < 1)
		return (val_errors(ERR_NOROOMS, NULL, 0, 0));
	while (i < ptr_farm.nb_nodes && ptr_farm.nodes[i])
	{
		if (lemin_check_edge_out(ptr_farm.nodes[i]->edges_out) == 1)
			ptr_farm.nodes[i]->edges_out = NULL;
		lemin_check_edge_in(ptr_farm.nodes[i]->edges_in, i);
		i++;
	}
	return (0);
}