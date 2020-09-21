/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 21:22:08 by sschmele          #+#    #+#             */
/*   Updated: 2020/09/21 23:18:31 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "validator.h"

int			val_start_validation(int argc, char **argv)
{
	int		i;
	
	i = 0;
	if (argc > 1)
		i = val_check_options(argc, argv);
	if (i == VAL_ERROR)
		return (VAL_ERROR);
	// if (i > 0 && i < argc)
	// 	val_check_arguments(argc - i, &argv[i]);
	return (0);
}

int			val_check_options(int argc, char **argv)
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
	return (0);
}

int			val_check_arguments(int argc, char **argv)
{
	return (0);
}