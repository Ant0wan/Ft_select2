/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 13:20:20 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/30 13:20:47 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	frame(struct s_select *data)
{
	int	i;

	// get windows size to chekc limits
	termsize(data);

	// Draw frame corners
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
