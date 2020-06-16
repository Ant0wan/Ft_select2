/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 17:32:47 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/16 10:02:39 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static struct s_element	*element_per_column(struct s_select *data, struct s_element *e)
{
	struct s_element	*first_e;
	int			nb_el;
	int			capacity;
	int			width;

	nb_el = 0;
	first_e = e;
	if (data->frame_enabled)
		capacity = data->win.ws_row - 2;
	else
		capacity = data->win.ws_row;
	while (e && nb_el <= capacity)
	{
		if (e->len > width)
			width = e->len;
		++nb_el;
		e = e->next;
	}
	first_e->c_width = width;
	return (e);
}

static struct s_element	*set_columns(struct s_select *data, struct s_element *e)
{
	struct s_element	*first_e;
	struct s_element	*col_leader;
	int			remaining_width;

	if (data->frame_enabled)
		remaining_width = data->win.ws_col - 2;
	else
		remaining_width = data->win.ws_col;
	first_e = e;
	while (e && remaining_width > 0)
	{
		col_leader = e;
		e = element_per_column(data, e);
		remaining_width -= (col_leader->c_width + 1);
		
	}
	return (first_e);
}

static void	set_pages(struct s_select *data)
{
	set_columns(data, data->elements);
/*
	struct s_element	*e;
	int			nb_col;

	nb_col = 0;
	e = data->elements;
	while (set_columns(data, e))
	{
		++nb_col;
	}
*/	data->elements->page = 1;
}

int	current_page_nb(struct s_select *data)
{
	struct s_element	*c;

	c = data->cursor;
	while (c)
	{
		if (c->page)
			return (c->page);
		else if (c == data->elements)
			return (0);
		c = c->previous;
	}
	return (0);
}

void	page(struct s_select *data)
{
	set_pages(data);
	data->psum = 10; // SHoud be computed at each resize
	data->pnb = current_page_nb(data); // SHould be computed what element is underlined
	if (data->psum > 1 && data->frame_enabled && data->win.ws_col > 10) // No need to display pages if only 1 page
	{
		tputs(tgoto(data->termcaps.cm, data->win.ws_col / 2 - 5, data->win.ws_row - 2), 1, output);
		ft_dprintf(data->fd, "%3d/%-3d", data->pnb, data->psum);
	}
//	display_elements(data);
}
