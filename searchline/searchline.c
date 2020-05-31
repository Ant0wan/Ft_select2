/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 10:18:58 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 10:27:03 by abarthel         ###   ########.fr       */
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
//		ft_printf("\n%d %d %d %d %d %d %d\n", (int)c.buf[0], (int)c.buf[1], (int)c.buf[2], (int)c.buf[3], (int)c.buf[4], (int)c.buf[5], (int)c.buf[6]);
		if (enter_rc(c))
			return ;
		else if (isstdkey(c.value))
			(g_standard_keymap[c.value].func)(c.value);
		else if (isctrlkey(c))
		{
			if (mvctrlkey(c))
				c.buf[2] = c.buf[5] + 20;
			(g_ctlx_keymap[(int)c.buf[2]].func)();
		}
		else if (ismetachar(c))
			(g_meta_keymap[(int)c.buf[1]].func)();
		else
			paste_via_input(c.value);
		*value = g_line.line;
	}
}

void		*searchline(struct s_select *data)
{
	if (data->search_line)
		ft_memdel((void**)&data->search);
	init_line_buffer(data);
	update_line();
	searchline_internal(data);
}
