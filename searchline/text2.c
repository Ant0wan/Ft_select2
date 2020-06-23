/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:14:17 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/23 10:53:05 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchline.h"

void	rl_insert(struct s_select *data, int c)
{
	char s[1];

	s[0] = (char)c;
	insert_text(data, s, 1);
}

void	cursor_l(struct s_select *data)
{
	if (data->sl_cpos > 0)
	{
		data->sl_cpos--;
		bar(data);
	}
}

void	cursor_r(struct s_select *data)
{
	if (data->sl_cpos == data->sl_len)
	{
		if (data->suggestion)
		{
			clear_line(data);
			insert_text(data, data->suggestion->arg,
			data->suggestion->len);
		}
	}
	else if (data->sl_cpos < data->sl_len)
	{
		data->sl_cpos++;
		bar(data);
	}
}

void	tab_autocomp(struct s_select *data)
{
	if (data->sl_cpos == data->sl_len)
	{
		if (data->suggestion)
		{
			clear_line(data);
			insert_text(data, data->suggestion->arg,
			data->suggestion->len);
		}
	}
}
