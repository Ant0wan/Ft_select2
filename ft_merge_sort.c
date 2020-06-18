/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 13:54:32 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/18 23:35:31 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static void				ft_split_lst(struct s_element **e)
{
	struct s_element	*find_last_link;

	find_last_link = *e;
	while (find_last_link->next != NULL)
	{
		find_last_link = find_last_link->next;
		if (find_last_link->next != NULL)
		{
			*e = (*e)->next;
			find_last_link = find_last_link->next;
		}
	}
}

static struct s_element	*ft_merge_list(struct s_select *data,
			struct s_element *lst1, struct s_element *lst2)
{
	struct s_element	*head;
	struct s_element	*tmp;

	head = NULL;
	fcompare(data, &lst1, &lst2, &head);
	tmp = head;
	while (lst1 != NULL && lst2 != NULL)
	{
		fcompare(data, &lst1, &lst2, &tmp->next);
		tmp = tmp->next;
	}
	while (lst1 != NULL)
	{
		tmp->next = lst1;
		lst1 = lst1->next;
		tmp = tmp->next;
	}
	while (lst2 != NULL)
	{
		tmp->next = lst2;
		lst2 = lst2->next;
		tmp = tmp->next;
	}
	return (head);
}

void					ft_merge_sort(struct s_element **e,
						struct s_select *data)
{
	struct s_element	*e1;
	struct s_element	*e2;

	if (*e == NULL || (*e)->next == NULL)
		return ;
	e1 = *e;
	ft_split_lst(e);
	e2 = (*e)->next;
	(*e)->next = NULL;
	ft_merge_sort(&e1, data);
	ft_merge_sort(&e2, data);
	*e = ft_merge_list(data, e1, e2);
}
