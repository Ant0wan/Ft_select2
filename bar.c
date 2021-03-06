/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bar.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 13:13:05 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/23 14:26:23 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		set_bar_color(struct s_select *data)
{
	tputs(tgoto(data->termcaps.cm, 0, data->win.ws_row), 1, output);
	tputs(data->termcaps.ce, 1, output);
	if (data->win.ws_col > 0)
		ft_dprintf(data->fd, "%s%*s", BFIELD, data->win.ws_col, " ");
	tputs(tgoto(data->termcaps.cm, 0, data->win.ws_row), 1, output);
}

static int	nb_selected(struct s_select *data)
{
	struct s_element	*e;
	int					i;

	i = 0;
	e = data->elements;
	while (e)
	{
		if (e->selected)
			++i;
		e = e->next;
	}
	return (i);
}

void		select_bar(struct s_select *data)
{
	if (data->win.ws_col >= 23)
	{
		ft_dprintf(data->fd, " %sSort:  %s  %s",
			BFIELD, data->sort->name, BFIELD);
	}
	if (data->win.ws_col >= 25 + 16)
		ft_dprintf(data->fd, "    Selected:%3d", nb_selected(data));
	ft_dprintf(data->fd, "%s", DEFAULT);
	if (data->win.ws_col >= 25 + 16 + 43)
	{
		tputs(tgoto(data->termcaps.cm, data->win.ws_col - 43,
		data->win.ws_row), 1, output);
		ft_dprintf(data->fd,
		"%s    Press <:> sort mode   </> search mode%s",
		GRMODE, DEFAULT);
	}
}

void		command_bar(struct s_select *data)
{
	if (data->win.ws_col >= 23)
	{
		ft_dprintf(data->fd, " %sSort:%s%s %s %s%s", BFIELD, RESFID,
		data->sort->prev ? ARLE : " ", data->sort->name,
		data->sort->next ? ARRI : " ", BFIELD);
	}
	if (data->win.ws_col >= 25 + 16)
		ft_dprintf(data->fd, "    Selected:%3d", nb_selected(data));
	ft_dprintf(data->fd, "%s", DEFAULT);
	if (data->win.ws_col >= 25 + 16 + 43)
	{
		ft_dprintf(data->fd,
		"%s    %sPress <ESC> or <ENTER> to quit mode%s",
		GRMODE, GRHELP, DEFAULT);
	}
}

void		search_errmsg(struct s_select *data)
{
	int	len_msg;

	len_msg = data->win.ws_col < 26 ? data->win.ws_col : 26;
	ft_dprintf(data->fd, "%s", SEAERR);
	if (write(data->fd, "Search: Pattern not found", len_msg) == -1)
		end_pgm(-126);
	if (data->win.ws_col >= 28 + 1)
	{
		ft_dprintf(data->fd, ": %.*s",
		data->win.ws_col - 28, data->search_line);
	}
	ft_dprintf(data->fd, "%s", DEFAULT);
	data->search_error = 1;
}

static void	search_area(struct s_select *data)
{
	static int	offset;

	offset = data->sl_cpos + 2 - data->win.ws_col;
	offset = offset > 0 ? offset : 0;
	if (offset > 0)
		ft_dprintf(data->fd, "<");
	else
		ft_dprintf(data->fd, "/");
	ft_dprintf(data->fd, "%.*s",
	data->win.ws_col - 2, &data->search_line[offset]);
	if (offset + data->win.ws_col < data->sl_len + 2)
		ft_dprintf(data->fd, ">");
	ft_dprintf(data->fd, "%s", DEFAULT);
	tputs(tgoto(data->termcaps.cm, data->sl_cpos - offset + 1,
	data->win.ws_row), 1, output);
}

void		search_bar(struct s_select *data)
{
	tputs(tgoto(data->termcaps.cm, 0, data->win.ws_row), 1, output);
	if (!data->search_error)
		search_area(data);
	else
	{
		set_bar_color(data);
		search_errmsg(data);
	}
}

static void	draw_bar(struct s_select *data)
{
	set_bar_color(data);
	if (data->mode == SELECT)
		select_bar(data);
	else if (data->mode == COMMAN)
		command_bar(data);
	else if (data->mode == SEARCH)
		search_bar(data);
}

void		bar(struct s_select *data)
{
	if (data->win.ws_row < 2)
		data->bar_enabled = 0;
	else
	{
		data->bar_enabled = 1;
		draw_bar(data);
	}
}
