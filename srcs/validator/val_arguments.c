/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 19:35:23 by sschmele          #+#    #+#             */
/*   Updated: 2020/09/25 11:44:01 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "validator.h"

int			val_check_options(char **argv)
{
	int		flags;

	flags = ft_find_options(OPTIONS_NUM,
		(char*[]){PROGRAM_OPTIONS, "--help"}, argv);
	if (flags < 0)
		return (val_errors(ERR_OPTION, NULL, 0, 1));
	if (flags & HELP_OPTION)
	{
		lemin_usage();
		return (STOP);
	}
	if (flags != HELP_OPTION)
		return (val_check_arguments(argv));
	return (0);
}

int			val_check_arguments(char **argv)
{
	int		i;

	i = 0;
	while (argv[++i])
	{
		if (argv[i][0] == '-')
		{
			if (!argv[i][1])
				return (val_errors(ERR_OPTION, NULL, 0, 1));
			if (argv[i][1] && argv[i][1] == '-' && !argv[i][2])
				return (val_errors(ERR_OPTION, NULL, 0, 1));
			if (argv[i][1] && argv[i][1] != '-')
				return ((val_check_program_option(argv[i],
					PROGRAM_OPTIONS, val_errors)) != 0 ?
					VAL_ERROR : 0);
		}
	}
	val_errors(ERR_ARG, NULL, 0, 0);
	return (0);
}

int			val_check_program_option(char *arg, char *options,
				int (f)(int error_index, char *arg, char end, int usage_needed))
{
	int		j;
	int		k;
	int		check;

	j = 0;
	check = 0;
	while (arg[++j])
	{
		k = -1;
		check = 0;
		while (options[++k])
		{
			if (arg[j] == options[k])
			{
				check = 1;
				break ;
			}
		}
		if (check == 0)
			return (f(ERR_OPTION, arg, 0, 1));
	}
	return (0);
}