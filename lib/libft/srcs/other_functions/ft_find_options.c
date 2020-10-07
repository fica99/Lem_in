/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 16:45:00 by sschmele          #+#    #+#             */
/*   Updated: 2020/10/06 23:37:57 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define ERR_OPTION			-1
#define CONTINUE			0
#define STOP				1
#define NUM_ARG				2
#define SUBOPTION			3
#define OPTION_FOUND		4
#define SUBOPTION_STARTS	16

static int	suboptions_proc(char *arri, int num,
				char *flags_arr[num], int *final)
{
	size_t	len;
	int		mask;
	int		i;

	if (arri[2] == '\0')
		return (STOP);
	len = SUBOPTION_STARTS;
	mask = 1;
	i = 0;
	while (++i < num)
	{
		if (ft_strcmp(arri, flags_arr[i]) == 0)
		{
			len += i - 1;
			mask = mask << len;
			*final |= mask;
			return (CONTINUE);
		}
	}
	return (ERR_OPTION);
}

/*
** First we form a mask for the final int and after "activate" the bit
*/

static int	options_proc(char arrij, char *flags_arr, int *final)
{
	int		k;
	size_t	len;
	int		mask;

	k = -1;
	len = ft_strlen(flags_arr);
	mask = 1;
	if (arrij == '-')
		return (SUBOPTION);
	while (flags_arr[++k])
	{
		if (arrij == flags_arr[k])
		{
			mask = mask << (len - k - 1);
			*final |= mask;
			return (CONTINUE);
		}
	}
	if (arrij >= '0' && arrij <= '9')
		return (NUM_ARG);
	return (ERR_OPTION);
}

/*
** Accepts argument after the valid flag as GNU lib does
*/

static int	options_in_arg(char *arri, int num,
				char *flags_arr[num], int *final)
{
	int		j;
	int		res;

	j = 0;
	while (arri[++j])
	{
		res = options_proc(arri[j], flags_arr[0], final);
		if (res == ERR_OPTION)
			return (ERR_OPTION);
		else if (res == SUBOPTION)
		{
			res = suboptions_proc(arri, num, flags_arr, final);
			if (res == STOP)
				return (STOP);
			else if (res == ERR_OPTION)
				return (ERR_OPTION);
			return (CONTINUE);
		}
	}
	return (CONTINUE);
}

/*
** The @final will be:
** 0000 0000 0000 0000
** 0000 0000 0000 0000
** 0000 0000 0000 0000 - sector for "suboptions" with "--"
** 0000 0000 0000 0000 - sector where bits are "options"
** will be activated
**
** Example:
** We send to the function: find_options(3,
** (char*[]){"elsrn", "--help", "--usage"},
** pos->ar_v) where 3 is the number of lines in the array,
** char*[] is the array
** itself, pos->ar_v is the argv array
** If @flags_arr[3]{"erlns", "--help", "--usage"} and
** @arr {"fc, "-r", "1", "10", "--help" "--" "--usage"}
**
** @final will be:
** 0000 0000 0000 0000
** 0000 0000 0000 0000
** 0000 0000 0000 0001 - "help" activated
** 0000 0000 0000 0100 - "r" activated
** usage is not activated because after "--"
** everything is regarded as arguments
*/

int			ft_find_options(int num, char *flags_arr[num], char **arr)
{
	int		i;
	int		final;
	int		res;

	i = 0;
	final = 0;
	while (arr[++i])
	{
		if (arr[i][0] != '-')
			continue;
		res = options_in_arg(arr[i], num, flags_arr, &final);
		if (res == ERR_OPTION)
			return (ERR_OPTION);
		else if (res == STOP)
			break ;
	}
	return (final);
}
