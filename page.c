/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 17:32:47 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/11 16:59:26 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
/*
static struct s_element	*element_per_column(struct s_select *data, struct s_element *e)
{
	struct s_element	*first_e;
	int			nb_el;
	int			capacity;
	int			width;

	nb_el = 0;
	first_e = e;
	if (data->frame_enabled)
		capacity = data->win.ws_row - 3;
	else
		nmax = data->win.ws_row - 1;
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
		remaining_width = data->win.ws_col - 3;
	else
		remaining_width = data->win.ws_col - 1;
	first_e = e;
	while (e)
	{
		col_leader = e;
		e = element_per_column(data, e);
	}
	return (first_e);
}

static void	set_pages(struct s_select *data)
{
	struct s_element	*e;
	int			nb_col;

	nb_col = 0;
	e = data->elements;
	while (set_columns(data, e))
	{
		++nb_col;
	}
	data->elements->page = 1;
}
*/
void	mark_elements(struct s_select *data)
{
	(void)data;
	// mark pages
}

void	page(struct s_select *data)
{
	data->psum = 10; // SHoud be computed at each resize
	data->pnb = 1; // SHould be computed what element is underlined
	if (data->psum > 1 && data->frame_enabled && data->win.ws_col > 10) // No need to display pages if only 1 page
	{
		tputs(tgoto(data->termcaps.cm, data->win.ws_col / 2 - 5, data->win.ws_row - 2), 1, output);
		ft_dprintf(data->fd, "%3d/%-3d", data->pnb, data->psum);
	}
	mark_elements(data);
	display_elements(data);
//	set_pages(data);
}
