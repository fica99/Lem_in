/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 19:09:42 by sschmele          #+#    #+#             */
/*   Updated: 2020/08/05 19:53:22 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list **begin_list)
{
	t_list	*tmp;

	tmp = *begin_list;
	if (tmp)
		while (tmp->next)
			tmp = tmp->next;
	return (tmp);
}
