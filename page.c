/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 17:32:47 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/16 18:38:58 by abarthel         ###   ########.fr       */
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

static struct s_element	*compute_column(struct s_select *data, struct s_element *e)
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
	fill_info(first_e, e, width);
	return (e);
}

static struct s_element	*compute_one_page(struct s_select *data, struct s_element *e)
{
	int			remaining_width;

	if (data->frame_enabled)
		remaining_width = data->win.ws_col - 2;
	else
		remaining_width = data->win.ws_col;
	while (e && remaining_width > 0)
	{
		e->page = data->psum;
		e = compute_column(data, e);
		if (e)
		{
			remaining_width -= e->c_width;
			remaining_width--;
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
	if (data->psum > 1 && data->frame_enabled && data->win.ws_col > 10) // No need to display pages if only 1 page
	{
		tputs(tgoto(data->termcaps.cm, data->win.ws_col / 2 - 5, data->win.ws_row - 2), 1, output);
		ft_dprintf(data->fd, "%3d/%-3d", data->pnb, data->psum);
	}
//	display_elements(data);
}
