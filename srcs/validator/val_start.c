/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 21:22:08 by sschmele          #+#    #+#             */
/*   Updated: 2020/09/23 10:38:54 by sschmele         ###   ########.fr       */
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
	// if (answer != 0)
	// 	val_errors(ERR_ARG, NULL, 0);
	if (val_read_stdinput() == VAL_ERROR)
		return (VAL_ERROR);
	return (0);
}

int			val_check_options(char **argv)
{
	int		flags;

	flags = ft_find_options(OPTIONS_NUM,
		(char*[]){PROGRAM_OPTIONS, "--help"}, argv);
	if (flags < 0)
		return (val_errors(ERR_OPTION, NULL, 1));
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
				return (val_errors(ERR_OPTION, NULL, 1));
			if (argv[i][1] && argv[i][1] == '-' && !argv[i][2])
				return (val_errors(ERR_OPTION, NULL, 1));
			if (argv[i][1] && argv[i][1] != '-')
				return ((val_check_program_option(argv[i],
					PROGRAM_OPTIONS, val_errors)) != 0 ?
					VAL_ERROR : 0);
		}
	}
	val_errors(ERR_ARG, NULL, 0);
	return (0);
}

int			val_check_program_option(char *arg, char *options,
				int (f)(int error_index, char *arg, int usage_needed))
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
			return (f(ERR_OPTION, arg, 1));
	}
	return (0);
}

int			val_read_stdinput(void)
{
	printf("reading from the stdinput\n");
	return (0);
}