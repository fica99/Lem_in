/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:58:48 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/21 23:12:47 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int argc, char **argv)
{
	int	answer;
	
	answer = val_start_validation(argc, argv);
	if (answer == VAL_ERROR)
		return (1);
	else if (answer == STOP)
		return (0);
	printf("\nGo to algorithm\n");
	return (0);
}

void	lemin_usage(void)
{
	ft_printf("%-10s %s [] < file or %s \"map\"\n",
		"usage:", PROGRAM_NAME, PROGRAM_NAME);
	ft_printf("%11s%s [--help]\n", "", PROGRAM_NAME);
}