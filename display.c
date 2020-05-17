/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 17:51:21 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/17 12:57:37 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	frame(struct s_select *data)
{
//	int	i;

	// get windows size to chekc limits
	ioctl(STDERR_FILENO, TIOCGWINSZ, &(data->win));
	// Draw frame corners
	(void)data;
	tputs(tgoto(data->termcaps.cm, 0, 0), 1, output);
	ft_dprintf(data->fd, "┌");
//	tputs(data->termcaps.cd, 1, output);
	sleep(2);
//	tputs(tgoto(data->termcaps.cm, 0, 0), 1, output);
//	tputs(data->termcaps.cd, 1, output);

//	i = 0;
//	while (++i < data->win.ws_col - 1)
//		ft_dprintf(data->fd, "─");

//	ft_printf("┐");
//	tputs(tgoto(tgetstr("cm", NULL), data->win.ws_col, 0), 1, output);
//
//	ft_printf("│");
//
//	tputs(tgoto(tgetstr("cm", NULL), 0, data->win.ws_row), 1, output);
//	ft_printf("└");
//
//	i = 0;
//	while (++i < data->win.ws_col - 1)
//		ft_printf("─");
//
//	tputs(tgoto(tgetstr("cm", NULL), data->win.ws_col, data->win.ws_row), 1, output);
//	ft_printf("┘");
}

void	display(struct s_select *data)
{
	frame(data);
}
