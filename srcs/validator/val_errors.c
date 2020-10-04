/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 22:25:32 by sschmele          #+#    #+#             */
/*   Updated: 2020/10/04 23:57:59 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "validator.h"

#define ERRORS_NUM 25

static char		*val_errors_types(int sequence_num)
{
	char		*seq_action[ERRORS_NUM];

	seq_action[0] = "invalid option";
	seq_action[1] = "the program accepts only standard input";
	seq_action[2] = "empty map line";
	seq_action[3] = "invalid map line: ";
	seq_action[4] = "not enough ants found";
	seq_action[5] = "not enough rooms found";
	seq_action[6] = "invalid room name: ";
	seq_action[7] = "\'##start\' not found";
	seq_action[8] = "\'##end\' not found";
	seq_action[9] = "room linked on itself: ";
	seq_action[10] = "no information about room found: ";
	seq_action[11] = "redefinition of information for room: ";
	seq_action[12] = "no possible solution with this map";
	seq_action[13] = "can not read from standard input";
	seq_action[14] = "no farm found";
	seq_action[15] = "too many ants found";
	seq_action[16] = "line starts with spaces";
	seq_action[17] = "line ends with spaces";
	seq_action[18] = "invalid coordinate: ";
	seq_action[19] = "not enough coordinates found";
	seq_action[20] = "too many coordinates found: only x and y needed";
	seq_action[21] = "start is redefined";
	seq_action[22] = "end is redefined";
	seq_action[23] = "link [room name1]-[room name2] needed";
	seq_action[24] = "no links between rooms found";
	return (seq_action[sequence_num]);
}

int				val_errors(int error_index, char *arg,
					char end, int usage_needed)
{
	char		*error_message;
	
	error_message = val_errors_types(error_index);
	ft_putstr_fd(PROGRAM_NAME, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(error_message, STDERR_FILENO);
	if (arg)
		ft_putchrendl_fd(arg, end, STDERR_FILENO);
	else
		ft_putchar_fd('\n', STDERR_FILENO);
	if (usage_needed == 1)
		lemin_usage();
	return (VAL_ERROR);
}