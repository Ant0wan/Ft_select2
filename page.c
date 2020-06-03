/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 17:32:47 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/03 18:37:01 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	page(struct s_select *data)
{
	data->page.total = 15;
	data->page.nb = 1;
	if (data->frame_enabled && data->win.ws_col > 24)
	{
		tputs(tgoto(data->termcaps.cm, data->win.ws_col / 2 - 5, data->win.ws_row - 2), 1, output);
		ft_dprintf(data->fd, "❮");
		ft_dprintf(data->fd, "%.*s", data->page.total > 16 ? 16 : data->page.total * 2, "――――――――");
		ft_dprintf(data->fd, "❯");
		tputs(tgoto(data->termcaps.cm,
			data->win.ws_col / 2 - 4 + (data->page.nb / data->page.total) * 8,
			data->win.ws_row - 2), 1, output);
		ft_dprintf(data->fd, "▮");
	}
}
/*
void	compute_nb_pages(struct s_select *data)
{
	data->page->total = 2;
}*/
