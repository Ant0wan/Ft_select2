/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 17:32:47 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/17 15:32:29 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static void	fill_info(struct s_element *start, struct s_element *end, int width)
{
	while (start)
	{
		if (start == end)
			break;
		start->c_width = width;
		start = start->next;
	}
}

static struct s_element	*compute_column(struct s_select *data, struct s_element *e, int c)
{
	struct s_element	*first_e;
	int			nb_el;
	int			capacity;
	int			width;
	int			r;

	nb_el = 0;
	first_e = e;
	if (data->frame_enabled)
		r = 1;
	else
		r = 0;
	if (data->frame_enabled)
		capacity = data->win.ws_row - 2 - 2;
	else
		capacity = data->win.ws_row - 2;
	while (e && nb_el <= capacity)
	{
		e->page = data->psum;
		if (e->len > width)
			width = e->len;
		e->r = r;
		++nb_el;
		++r;
		if (e == data->cursor)
			data->pnb = data->psum;
		e->c = c;
		e = e->next;
	}
	fill_info(first_e, e, width);
	return (e);
}

static struct s_element	*compute_one_page(struct s_select *data, struct s_element *e)
{
	int			remaining_width;
	int			c;

	if (data->frame_enabled)
	{
		c = 1;
		remaining_width = data->win.ws_col - 2;
	}
	else
	{
		c = 0;
		remaining_width = data->win.ws_col;
	}
	while (e && remaining_width > 0)
	{
		e = compute_column(data, e, c);
		if (e)
		{
			remaining_width -= e->c_width;
			remaining_width--;
			c += e->c_width + 1;
		}
	}
	return (e);
}

static void	compute_pages(struct s_select *data)
{
	struct s_element	*e;

	data->psum = 0;
	e = data->elements;
	while (e)
	{
		data->psum++;
		e = compute_one_page(data, e);
		if (e)
			e = e->next;
	}
}

void	page(struct s_select *data)
{
	compute_pages(data);
	if (data->psum > 1 && data->frame_enabled && data->win.ws_col > 10)
	{
		tputs(tgoto(data->termcaps.cm, data->win.ws_col / 2 - 5, data->win.ws_row - 2), 1, output);
		ft_dprintf(data->fd, "%3d/%-3d", data->pnb, data->psum);
	}
}
