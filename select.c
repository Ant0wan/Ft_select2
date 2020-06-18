/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:48:35 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/18 18:41:20 by abarthel         ###   ########.fr       */
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
	if (data->cursor->previous)
		data->cursor = data->cursor->previous;
	else
	{
		while (data->cursor->next)
			data->cursor = data->cursor->next;
	}
	page(data);
	data->no_refresh = 1;
}

void	cursor_next(struct s_select *data)
{
	if (data->cursor->next)
		data->cursor = data->cursor->next;
	else
		data->cursor = data->elements;
	page(data);
	data->no_refresh = 1;
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
