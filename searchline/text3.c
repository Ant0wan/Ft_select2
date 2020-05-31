/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:14:05 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 12:15:25 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchline.h"

void	clear_line(struct s_select *data)
{
	rl_home(data);
	tputs(tgoto(data->termcaps.cm, 1, data->win.ws_row), 1, output);
	tputs(data->termcaps.ce, 1, output);
	tputs(tgoto(data->termcaps.cm, 1, data->win.ws_row), 1, output);
	data->sl_len = 0;
	ft_bzero(data->search_line, data->sl_size);
}

void	rl_home(struct s_select *data)
{
	g_cursor.c_pos = g_dis.prompt_l;
	if (g_cursor.c_pos > 0)
		ft_putstr(tgoto(g_termcaps.ch, 0, g_cursor.c_pos));
	if (g_cursor.v_pos > 0)
	{
		ft_putstr(tgoto(g_termcaps.gup, 0, g_cursor.v_pos));
		g_cursor.v_pos = 0;
	}
	g_dis.cbpos = 0;
	update_line();
}

void	rl_end(void)
{
	g_cursor.c_pos = (g_dis.prompt_l + g_dis.cbpos) % g_sc.w;
	if (g_cursor.c_pos > 0)
	{
		ft_putstr(tgoto(g_termcaps.ch, 0, g_cursor.c_pos));
		g_dis.cbpos = g_line.len;
	}
	if (g_cursor.v_pos != g_dis.botl)
	{
		ft_putstr(tgoto(g_termcaps.gdo, 0, g_dis.botl - g_cursor.v_pos));
		g_dis.cbpos = g_line.len;
		g_cursor.v_pos = (g_dis.prompt_l + g_dis.cbpos) / g_sc.w;
	}
	update_line();
}

void	wd_right(void)
{
	while (g_line.line[g_dis.cbpos] == ' ' && g_dis.cbpos < g_line.len)
		cursor_r();
	while (g_line.line[g_dis.cbpos] != ' ' && g_dis.cbpos < g_line.len)
		cursor_r();
}
