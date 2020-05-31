/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:13:58 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 16:11:38 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchline.h"

void	wd_left(struct s_select *data)
{
	while (data->sl_cpos > 0 && data->search_line[data->sl_cpos - 1] == ' ')
		cursor_l(data);
	while (data->sl_cpos > 0 && data->search_line[data->sl_cpos - 1] != ' ')
		cursor_l(data);
}

void	paste_via_input(struct s_select *data, unsigned long v)
{
	union u_buffer	u;
	int				len;

	len = 0;
	u.value = v;
	while (len < 8 && u.buf[len])
		++len;
	insert_text(data, &(u.buf[0]), len);
}

/*
void	clear_eol(void)
{
	if (g_dis.cbpos != g_line.len)
	{
		g_clip.l = g_line.len - g_dis.cbpos;
		if (g_clip.str != NULL)
			free(g_clip.str);
		g_clip.str = ft_strndup(&(g_line.line[g_dis.cbpos]), g_clip.l);
		ft_bzero(&(g_line.line[g_dis.cbpos]), g_clip.l);
		g_line.len -= g_clip.l;
		bar(data);
	}
}*/
