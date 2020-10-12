/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 22:25:32 by sschmele          #+#    #+#             */
/*   Updated: 2020/10/12 16:51:38 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "validator.h"

#define ERRORS_NUM_FIRST 8
#define ERRORS_NUM_SECOND 17

static char		*val_errors_types_first(int sequence_num)
{
	char		*seq_action[ERRORS_NUM_FIRST];

	seq_action[0] = "invalid option";
	seq_action[1] = "the program accepts only standard input";
	seq_action[2] = "can not read from standard input";
	seq_action[3] = "no farm found";
	seq_action[4] = "empty map line";
	seq_action[5] = "invalid map line: ";
	seq_action[6] = "line starts with spaces";
	seq_action[7] = "line ends with spaces";
	return (seq_action[sequence_num]);
}

static char		*val_errors_types_second(int sequence_num)
{
	char		*seq_action[ERRORS_NUM_SECOND];

	seq_action[0] = "not enough ants found";
	seq_action[1] = "too many ants found";
	seq_action[2] = "not enough rooms found";
	seq_action[3] = "\'##start\' not found";
	seq_action[4] = "start is redefined";
	seq_action[5] = "\'##end\' not found";
	seq_action[6] = "end is redefined";
	seq_action[7] = "no room after command found";
	seq_action[8] = "invalid room name: ";
	seq_action[9] = "no information about room found: ";
	seq_action[10] = "redefinition of information for room: ";
	seq_action[11] = "invalid coordinate: ";
	seq_action[12] = "not enough coordinates found";
	seq_action[13] = "too many coordinates found: only x and y needed";
	seq_action[14] = "link [room name1]-[room name2] needed";
	seq_action[15] = "room linked on itself: ";
	seq_action[16] = "no possible solution with this map";
	return (seq_action[sequence_num]);
}

int				val_errors(int error_index, char *arg,
					char end, int usage_needed)
{
	char		*error_message;

	if (error_index < ERRORS_NUM_FIRST)
		error_message = val_errors_types_first(error_index);
	else
		error_message = val_errors_types_second(error_index - ERRORS_NUM_FIRST);
	ft_putstr_fd(PROGRAM_NAME, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(error_message, STDERR_FILENO);
	if (arg)
	{
		if (arg[0] == end)
		{
			ft_putchar_fd(arg[0], STDERR_FILENO);
			ft_putchrendl_fd(arg + 1, end, STDERR_FILENO);
		}
		else
			ft_putchrendl_fd(arg, end, STDERR_FILENO);
	}
	else
		ft_putchar_fd('\n', STDERR_FILENO);
	if (usage_needed == 1)
		lemin_usage();
	return (VAL_ERROR);
}
