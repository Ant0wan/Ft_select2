/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 21:36:05 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/19 11:01:20 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		init_sort_list(struct s_select *data)
{
	static struct s_sort	alpha;
	static struct s_sort	size;
	static struct s_sort	time;
	static struct s_sort	type;
	static struct s_sort	uid;

	alpha.prev = NULL;
	alpha.next = &size;
	size.prev = &alpha;
	size.next = &time;
	time.prev = &size;
	time.next = &type;
	type.prev = &time;
	type.next = &uid;
	uid.prev = &type;
	uid.next = NULL;
	alpha.name = "alphabetical";
	size.name = "    size    ";
	time.name = "    time    ";
	type.name = "    type    ";
	uid.name = "    uid     ";
	data->sort = &alpha;
	alpha.fcmp = &alpha_compare;
	size.fcmp = &size_compare;
	time.fcmp = &time_compare;
	type.fcmp = &type_compare;
	uid.fcmp = &uid_compare;
}

void		right_sort_mode(struct s_select *data, union u_buffer input)
{
	(void)input;
	if (data->sort->next)
	{
		data->sort = data->sort->next;
		bar(data);
	}
	data->no_refresh = 1;
}

void		left_sort_mode(struct s_select *data, union u_buffer input)
{
	(void)input;
	if (data->sort->prev)
	{
		data->sort = data->sort->prev;
		bar(data);
	}
	data->no_refresh = 1;
}

void		fcompare(struct s_select *data, struct s_element **e1,
	struct s_element **e2, struct s_element **h)
{
	if (data->sort->fcmp(*e1, *e2) > 0)
	{
		*h = *e2;
		*e2 = (*e2)->next;
	}
	else
	{
		*h = *e1;
		*e1 = (*e1)->next;
	}
}

void		sort(struct s_select *data)
{
	struct s_element	*e;

	if (data && data->elements && data->elements->next)
		ft_merge_sort(&data->elements, data);
	e = data->elements;
	data->elements->previous = NULL;
	while (e)
	{
		if (e->next)
			e->next->previous = e;
		e = e->next;
	}
}
