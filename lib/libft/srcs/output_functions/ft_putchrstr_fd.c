/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchrstr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:56:53 by sschmele          #+#    #+#             */
/*   Updated: 2020/10/06 23:36:56 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putchrstr_fd(char *str, char x, int fd)
{
	int				i;

	i = 0;
	while (str[i] && str[i] != x)
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
}
