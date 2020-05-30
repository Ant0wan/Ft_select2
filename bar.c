/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bar.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 13:13:05 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/30 14:20:42 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

#define BFIELD "\033[40;38;5;82m"
#define RESFID "\033[30;48;5;82m"
#define GRHELP "\033[37;40;5m"
#define GRMODE "\033[37;40;2m"
#define SEAERR "\033[97;41m"

#define ARLE "◄"
#define ARRI "►"

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
	ft_dprintf(data->fd, " %sSort:  %s  %s\t", BFIELD, data->sort->name, BFIELD);
	ft_dprintf(data->fd, "\tSelected: %s%3d%s", RESFID, 0, DEFAULT);
	ft_dprintf(data->fd, "\t\t\t\t\t%s<:> sort mode   </> search mode   <r> reset%s", GRMODE, DEFAULT); // Should be right centered
}

void	command_bar(struct s_select *data)
{
	ft_dprintf(data->fd, " %sSort:%s%s %s %s%s\t", BFIELD, RESFID, data->sort->prev ? ARLE : " ", data->sort->name, data->sort->next ? ARRI : " ", BFIELD);
	ft_dprintf(data->fd, "\tSelected: %s%3d%s", RESFID, 0, DEFAULT);
	ft_dprintf(data->fd, "\t%sPress <ESC> to quit mode%s", GRHELP, DEFAULT); // Should be right centered
}

void	search_bar(struct s_select *data)
{
	ft_dprintf(data->fd, "/keyword");
	ft_dprintf(data->fd, "%sSearch: Pattern not found: keyword%s",SEAERR, DEFAULT);
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
