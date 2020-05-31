/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:14:17 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 10:49:58 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchline.h"

void	rl_insert(struct s_select *data, int c)
{
	char s[1];

	s[0] = (char)c;
	insert_text(data, s, 1);
}

/*
void	cursor_l(void)
{
	if (data->sl_cpos > 0)
	{
		ft_putstr(tgoto(g_termcaps.backspace, 0, 0));
		--g_cursor.c_pos;
	}
	else
	{
		g_cursor.c_pos = g_sc.w - 1;
		--g_cursor.v_pos;
		ft_putstr(tgoto(g_termcaps.up, 0, 0));
		ft_putstr(tgoto(g_termcaps.ch, 0, g_cursor.c_pos));
	}
	data->sl_cpos -= 1;
	update_line();
}

void	cursor_r(void)
{
	if (data->sl_cpos < data->sl_len)
	{
		if (g_cursor.c_pos == g_sc.w)
		{
			g_cursor.c_pos = 0;
			++g_cursor.v_pos;
			ft_putstr(tgoto(g_termcaps.do1, 0, 0));
			ft_putstr(tgoto(g_termcaps.ch, 0, g_cursor.c_pos));
		}
		else
		{
			++g_cursor.c_pos;
			ft_putstr(tgoto(g_termcaps.forward_char, 0, 0));
		}
		data->sl_cpos += 1;
		update_line();
	}
}

void	cursor_d(void)
{
	int len_last_line;

	if (g_cursor.v_pos != g_dis.botl)
	{
		len_last_line = (g_dis.prompt_l + data->sl_len) % g_sc.w;
		if (g_cursor.v_pos == g_dis.botl - 1
				&& g_cursor.c_pos > len_last_line)
		{
			ft_putstr(tgoto(g_termcaps.ch, 0, len_last_line));
			data->sl_cpos = data->sl_len;
		}
		else
			data->sl_cpos += g_sc.w;
		++g_cursor.v_pos;
		ft_putstr(tgoto(g_termcaps.do1, 0, 0));
		update_line();
	}
}*/
