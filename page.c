/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 17:32:47 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/18 23:51:01 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static int	get_maxlen(struct s_select *data, int column_length,
		struct s_element *e)
{
	int	maxlen;
	int	r;

	maxlen = 0;
	r = data->frame_enabled / 2;
	while (e && column_length)
	{
		if (maxlen < e->len)
			maxlen = e->len;
		column_length--;
		e->r = r;
		e->page = data->psum;
		r++;
		e = e->next;
	}
	return (maxlen);
}

static void	set_column_element(struct s_element **e, int maxlen,
		int column_length, int column_position)
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
	int	column_length;
	int	column_position;
	int	maxlen;

	column_length = data->win.ws_row - data->frame_enabled - data->bar_enabled;
	column_position = data->frame_enabled / 2;
	if (column_length <= 0)
		return ;
	while (*e)
	{
		maxlen = get_maxlen(data, column_length, *e);
		if (column_position != data->frame_enabled / 2)
		{
			if (column_position + maxlen + (data->frame_enabled / 2)
				> data->win.ws_col)
				return ;
		}
		maxlen = data->win.ws_col - (data->frame_enabled) < maxlen ?
			data->win.ws_col - (data->frame_enabled) : maxlen;
		set_column_element(e, maxlen, column_length, column_position);
		column_position += maxlen + 1;
	}
}

static void	compute_pages(struct s_select *data)
{
	struct s_element	*e;

	data->psum = 0;
	e = data->elements;
	while (e)
	{
		++data->psum;
		set_page(data, &e);
	}
}

void		page(struct s_select *data)
{
	compute_pages(data);
	if (data->psum > 1 && data->frame_enabled && data->win.ws_col > 10)
	{
		tputs(tgoto(data->termcaps.cm, data->win.ws_col / 2 - 5,
		data->win.ws_row - 2), 1, output);
		ft_dprintf(data->fd, "%3d/%-3d", data->cursor->page, data->psum);
	}
	display_page(data);
}
