/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 10:18:58 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 18:46:46 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchline.h"

static void	searchline_internal(struct s_select *data)
{
	union u_buffer	c;

	c.value = 1;
	while (c.value)
	{
		c = read_key();
		if (enter_rc(c))
			return (check_occur(data));
		else if (c.value == 27)
			return ;
		else if (isstdkey(c.value))
			(data->search_keymap.std[c.value])(data, c);
		else if (isctrlkey(c))
		{
			if (mvctrlkey(c))
				c.buf[2] = c.buf[5] + 20;
			(data->search_keymap.ctrl[(int)c.buf[2]])(data, c);
		}
		else if (ismetachar(c))
			(data->search_keymap.meta[(int)c.buf[1]])(data, c);
		else
			paste_via_input(data, c.value);
		disp_sug(data);
	}
}

void		searchline(struct s_select *data)
{
	if (data->search_line)
		ft_memdel((void**)&data->search_line);
	init_line_buffer(data);
	bar(data);
	searchline_internal(data);
	data->sl_size = 0;
	data->sl_cpos = 0;
	data->sl_len = 0;
}
