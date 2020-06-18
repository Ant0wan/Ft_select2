/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 13:20:20 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/18 23:31:15 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	draw_frame(struct s_select *data)
{
	int	i;

	tputs(tgoto(data->termcaps.cm, 0, 0), 1, output);
	ft_dprintf(data->fd, "┌");
	i = 0;
	while (++i < data->win.ws_col - 1)
		ft_dprintf(data->fd, "─");
	ft_dprintf(data->fd, "┐");
	i = 0;
	while (++i < data->win.ws_row - 2)
	{
		tputs(tgoto(data->termcaps.cm, 0, i), 1, output);
		ft_dprintf(data->fd, "│");
		tputs(tgoto(data->termcaps.cm, data->win.ws_col, i), 1, output);
		ft_dprintf(data->fd, "│");
	}
	tputs(tgoto(data->termcaps.cm, 0, data->win.ws_row - 2), 1, output);
	ft_dprintf(data->fd, "└");
	i = 0;
	while (++i < data->win.ws_col - 1)
		ft_dprintf(data->fd, "─");
	ft_dprintf(data->fd, "┘");
}

void	frame(struct s_select *data)
{
	tputs(tgoto(data->termcaps.cl, 0, 0), 1, output);
	termsize(data);
	if (data->win.ws_row < 4 || data->win.ws_col < 3)
		data->frame_enabled = 0;
	else
	{
		data->frame_enabled = 2;
		draw_frame(data);
	}
}
