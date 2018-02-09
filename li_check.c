/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:56:24 by zweng             #+#    #+#             */
/*   Updated: 2018/02/09 20:22:21 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		li_check_lstrooms(t_list *lst)
{
	t_list	*head;
	t_room	*r1;
	t_room	*r2;

	if (!lst)
		return (0);
	while (lst)
	{
		head = lst->next;
		r1 = (t_room *)lst->content;
		while (head)
		{
			r2 = (t_room *)head->content;
			if ((!r1 && !r2 && r1->x == r2->x && r1->y == r2->y) ||
			(!(r1->name) && !(r2->name) && !ft_strcmp(r1->name, r2->name)))
				return (0);
			head = head->next;
		}
		lst = lst->next;
	}
	return (1);
}
