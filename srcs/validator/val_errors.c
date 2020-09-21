/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 22:25:32 by sschmele          #+#    #+#             */
/*   Updated: 2020/09/21 23:05:00 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "validator.h"

#define ERRORS_NUM 12

static char		*val_errors_types(int sequence_num)
{
	static char	*seq_action[ERRORS_NUM]; //ask

	seq_action[0] = "invalid option";
	seq_action[1] = "no argument or map found";
	seq_action[2] = "empty map line";
	seq_action[3] = "invalid map line: ";
	seq_action[4] = "not enough ants found";
	seq_action[5] = "not enough rooms found";
	seq_action[6] = "invalid values in the line: ";
	seq_action[7] = "\'##start\' not found";
	seq_action[8] = "\'##end\' not found";
	seq_action[9] = "room linked on itself: ";
	seq_action[10] = "no information about room found: ";
	seq_action[11] = "redefinition of information: ";
	return (seq_action[sequence_num]);
}

int				val_errors(int error_index, char *arg, int usage_needed)
{
	char		*error_message;
	
	error_message = val_errors_types(error_index);
	ft_putstr_fd(PROGRAM_NAME, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(error_message, STDERR_FILENO);
	if (arg)
		ft_putendl_fd(arg, STDERR_FILENO);
	else
		ft_putchar_fd('\n', STDERR_FILENO);
	if (usage_needed == 1)
		lemin_usage();
	return (VAL_ERROR);
}