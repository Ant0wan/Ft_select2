/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:14:05 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/19 11:07:20 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchline.h"

void	clear_line(struct s_select *data)
{
	rl_home(data);
	data->sl_len = 0;
	ft_bzero(data->search_line, data->sl_size);
	bar(data);
}

void	rl_home(struct s_select *data)
{
	if (data->sl_cpos > 0)
	{
		data->sl_cpos = 0;
		tputs(tgoto(data->termcaps.cm, 1,
		data->win.ws_row), 1, output);
		bar(data);
	}
}

void	rl_end(struct s_select *data)
{
	if (data->sl_cpos < data->sl_len)
	{
		data->sl_cpos = data->sl_len;
		tputs(tgoto(data->termcaps.cm, data->sl_len,
		data->win.ws_row), 1, output);
		bar(data);
	}
}

void	wd_right(struct s_select *data)
{
	while (data->search_line[data->sl_cpos] == ' '
		&& data->sl_cpos < data->sl_len)
		cursor_r(data);
	while (data->search_line[data->sl_cpos] != ' '
		&& data->sl_cpos < data->sl_len)
		cursor_r(data);
}
