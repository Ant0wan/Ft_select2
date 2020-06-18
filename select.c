/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:48:35 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/18 19:49:33 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	set_select_mode(struct s_select *data)
{
	static struct s_sort	*lastsort;

	if (lastsort == data->sort)
		data->no_refresh = 1;
	data->mode = SELECT;
	data->search_error = 0;
	sort(data);
}

void	quit(struct s_select *data, union u_buffer input)
{
	(void)data;
	(void)input;
	end_pgm(-128);
}

void	cursor_prev(struct s_select *data)
{
	int p;

	p = data->cursor->page;
	if (data->cursor->previous)
		data->cursor = data->cursor->previous;
	else
	{
		while (data->cursor->next)
			data->cursor = data->cursor->next;
	}
	if (data->cursor->page == p)
		data->no_refresh = 1;
	page(data);
}

void	cursor_next(struct s_select *data)
{
	int p;

	p = data->cursor->page;
	if (data->cursor->next)
		data->cursor = data->cursor->next;
	else
		data->cursor = data->elements;
	if (data->cursor->page == p)
		data->no_refresh = 1;
	page(data);
}

void	select_it(struct s_select *data)
{
	if (data->cursor)
		data->cursor->selected ^= 1;
	cursor_next(data);
	bar(data);
}

void	del_cursor_element(struct s_select *data)
{
	struct s_element	*e;

	e = NULL;
	if (data->cursor->next)
		e = data->cursor->next;
	else if (data->cursor->previous)
		e = data->cursor->previous;
	del_one(data);
	data->cursor = e;
	if (!data->cursor)
		end_pgm(-128);
}

void	next_page(struct s_select *data)
{
	struct s_element *e;
	int	p;

	if (data->cursor->page == data->psum)
	{
		data->no_refresh = 1;
		return ;
	}
	e = data->cursor;
	p = e->page;
	while (e && e->page == p)
		e = e->next;
	if (e)
		data->cursor = e;
	page(data);
}

void	prev_page(struct s_select *data)
{
	struct s_element *e;
	int	page_target;

	e = data->cursor;
	if (e->page == 1)
	{
		data->cursor = data->elements;
		data->no_refresh = 1;
	}
	else if (e->page == 2)
		data->cursor = data->elements;
	else
	{
		page_target = e->page - 1;
		while (e->previous->page > page_target - 1)
			e = e->previous;
		if (e)
			data->cursor = e;
	}
	page(data);
}
