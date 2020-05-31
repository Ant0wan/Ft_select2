/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:20:42 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 12:51:19 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchline.h"
#include "../select.h"

void		update_line(struct s_select *data)
{
	// Clear line
	tputs(tgoto(data->termcaps.cm, 1, data->win.ws_row), 1, output);
	tputs(data->termcaps.ce, 1, output);
	tputs(tgoto(data->termcaps.cm, 1, data->win.ws_row), 1, output);
	set_bar_color(data);
	ft_dprintf(data->fd, "%s/", BFIELD);

	// Print line
	ft_dprintf(data->fd, "%s", data->search_line);
	ft_dprintf(data->fd, "%s", DEFAULT);

	// Go back to cursor position
	tputs(tgoto(data->termcaps.cm, data->sl_cpos, data->win.ws_row), 1, output);
}
