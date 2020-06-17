/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 17:32:47 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/17 19:07:38 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
/*
static void	compute_pages(struct s_select *data)
{
	struct s_element w = data->elements;

	// Width of column and row nb
	int column_width = 0;
	int column_position = 0;

	// Number of element per column
	int column_length = 0;

	column_length = data->win.ws_row - data->frame_enabled - bar_enabled;

	int row_position = 0;
	while (w && column_length)
	{
		// Get max len in column
		column_width = column_length > w->len ? column_length : w->len;

		// Give row position to element
		w->r = row_position;
		w->c = column_position;
		++row_position;

		// Decount for elements to handle
		--column_length;
		w = w->next;
	}
	column_position += column_width + 1;
}*/

static int	get_maxlen(struct s_select *data, int column_length, struct s_element *e)
{
	int maxlen = 0;
	int r = data->frame_enabled / 2;

	while (e && column_length)
	{
		if (maxlen < e->len)
			maxlen = e->len;
		column_length--;
		e->r = r;
		r++;
		e = e->next;
	}
	return (maxlen);
}
static void	set_column_element(struct s_element **e, int maxlen, int column_length, int column_position)
{
	while (*e && column_length)
	{
		(*e)->c_width = maxlen;
		(*e)->c = column_position;
		column_length--;
		*e = (*e)->next;
	}
}

static void	set_page(struct s_select *data, struct s_element **e)
{
	int column_length = data->win.ws_row - data->frame_enabled - data->bar_enabled;
	int column_position = data->frame_enabled / 2;
	int maxlen;

	++data->psum;
	if (column_length <= 0)
		return ;

	while (*e)
	{
		maxlen = get_maxlen(data, column_length, *e);
		if (column_position != data->frame_enabled / 2)
		{ // Case second column need check for space
			if (column_position + maxlen + (data->frame_enabled / 2) > data->win.ws_col)
				return;
		}
		maxlen = data->win.ws_col - (data->frame_enabled / 2) < maxlen ? data->win.ws_col - (data->frame_enabled / 2) : maxlen;
		set_column_element(e, maxlen, column_length, column_position);
		column_position += maxlen + 1;
	}
}

static void	compute_pages(struct s_select *data)
{
	struct s_element	*e;

	data->psum = 0;
	e = data->elements;
	set_page(data, &e);

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
