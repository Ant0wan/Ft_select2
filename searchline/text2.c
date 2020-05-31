/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:14:17 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 15:53:26 by abarthel         ###   ########.fr       */
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
		// Cursor should be set as visible when in line edition
		data->sl_cpos--;
		bar(data);
	}
}

void	cursor_r(struct s_select *data)
{
	if (data->sl_cpos < data->sl_len)
	{
		// Cursor should be set as visible when in line edition
		data->sl_cpos++;
		bar(data);
	}
}
