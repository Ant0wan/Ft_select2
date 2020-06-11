/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 13:20:20 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/11 16:34:37 by abarthel         ###   ########.fr       */
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
	// get windows size to chekc limits
	termsize(data);

	// Check if there is enough space to display the frame
	if (data->win.ws_row < 4 || data->win.ws_col < 3)
		data->frame_enabled = 0; // Not enough space to display frame and bar and an element
	else
	{
		data->frame_enabled = 1;
		// Draw frame corners
		draw_frame(data);
	}
}
