/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bar.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 13:13:05 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 10:54:44 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static void	set_bar_color(struct s_select *data)
{
	int	i;

	i = data->win.ws_col;
	while (i)
	{
		tputs(tgoto(data->termcaps.cm, i, data->win.ws_row), 1, output);
		ft_dprintf(data->fd, "%s ", BFIELD);
		--i;
	}
	tputs(tgoto(data->termcaps.cm, 0, data->win.ws_row), 1, output);
}

void	select_bar(struct s_select *data)
{
	if (data->win.ws_col >= 23)
		ft_dprintf(data->fd, " %sSort:  %s  %s", BFIELD, data->sort->name, BFIELD); // len up to 25
	if (data->win.ws_col >= 25 + 16)
		ft_dprintf(data->fd, "    Selected:%3d", 0); // len up to 16
	ft_printf("%s", DEFAULT);
	if (data->win.ws_col >= 25 + 16 + 55)
	{
		tputs(tgoto(data->termcaps.cm, data->win.ws_col - 55, data->win.ws_row), 1, output);
		ft_dprintf(data->fd, "%s    Press <:> sort mode   </> search mode   <r> reset%s", GRMODE, DEFAULT); // len up to 55
	}
}

void	command_bar(struct s_select *data)
{
	if (data->win.ws_col >= 23)
		ft_dprintf(data->fd, " %sSort:%s%s %s %s%s", BFIELD, RESFID, data->sort->prev ? ARLE : " ", data->sort->name, data->sort->next ? ARRI : " ", BFIELD);
	if (data->win.ws_col >= 25 + 16)
		ft_dprintf(data->fd, "    Selected:%3d", 0);
	ft_printf("%s", DEFAULT);
	if (data->win.ws_col >= 25 + 16 + 55) // limit is max len of help msg
		ft_dprintf(data->fd, "%s    %sPress <ESC> to quit mode%s", GRMODE, GRHELP, DEFAULT); // len up to 28
	//	ft_dprintf(data->fd, "\t%sPress <ESC> to quit mode%s", GRHELP, DEFAULT);
	//	ft_dprintf(data->fd, "\t%sPress <ESC> to quit mode%s", GRMODE, DEFAULT);
}

void	search_errmsg(struct s_select *data)
{
	int	len_msg;

	len_msg = data->win.ws_col < 35 ? data->win.ws_col : 35;
	ft_dprintf(data->fd, "%s", SEAERR);
	write(data->fd, "Search: Pattern not found: keyword", len_msg);
	ft_dprintf(data->fd, "%s", DEFAULT);
	data->search_error = 1;
}

void	readl(struct s_select *data)
{
	union u_buffer	c;

	ft_dprintf(data->fd, "/");
	c.value = 1;
	// Need line editing here with range scrolling <text>!
	while (c.value)
	{
		c = read_key();
		if (c.buf[0] == '\n' || !isprintchr(c.value))
			break;
		else
			ft_printf("%c", c.buf[0]);
	}
}

void	search_bar(struct s_select *data)
{
	if (!data->search_error)
		readl(data);
	tputs(tgoto(data->termcaps.cm, 0, data->win.ws_row), 1, output);
	// If pattern not found
		search_errmsg(data);
	// If pattern is found, select the found word and go back to selection mode
//		set_bar_color(data);
//		set_select_mode(data, c);
}

static void	draw_bar(struct s_select *data)
{
	// Set bar color
	set_bar_color(data);

	// Sort mode : escape mode and selection mode
	if (data->mode == SELECT)
		select_bar(data);
	else if (data->mode == COMMAN)
		command_bar(data);
	else if (data->mode == SEARCH)
		search_bar(data);
}

void	bar(struct s_select *data)
{
	// Window size should be computed before call this module
	if (data->win.ws_row < 2)
		data->bar_enabled = 0;
	else
	{
		data->bar_enabled = 1;
		draw_bar(data);
	}

}
