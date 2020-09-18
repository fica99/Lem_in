/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree_current.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:34:46 by sschmele          #+#    #+#             */
/*   Updated: 2020/08/06 01:03:23 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstfree_current(t_list **head)
{
	t_list	*delete;
	t_list	*save_next;

	if ((*head)->next)
	{
		delete = *head;
		save_next = (*head)->next;
		*head = save_next;
		free(delete);
		delete = NULL;
	}
	else
	{
		free(*head);
		*head = NULL;
	}
	return (0);
}
