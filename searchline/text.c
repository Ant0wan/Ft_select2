/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:16:27 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 10:28:08 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchline.h"

void		init_line_buffer(struct s_select *data)
{
	data->sl_size = 512;
	data->search_line = (char*)malloc(sizeof(char) * data->sl_size);
	ft_bzero(data->search_line, data->sl_size);
	data->sl_cbpos = 0;
	data->sl_len = 0;
}

void		l_expand(void)
{
	char	*new;
	size_t	lold;

	lold = g_line.size_buf;
	g_line.size_buf = lold * 2;
	new = (char*)malloc(sizeof(char) * g_line.size_buf);
	ft_bzero(new, lold * 2);
	ft_strncpy(new, g_line.line, lold);
	free(g_line.line);
	g_line.line = new;
}

void		insert_text(const char *string, int len)
{
	if (g_vim_mode == 0)
	{
		g_add_back_buf += len;
		if (g_add_back_buf > 20)
		{
//			ft_printf("\n\nH\n\n");
			g_add_back_buf = 0;
			add_back();
		}
	}
	if (g_replace_mode)
		return replace_text(string, len);
	while (len + g_line.len >= g_line.size_buf)
		l_expand();
	if (g_dis.cbpos < g_line.len)
	{
		ft_memmove(&(g_line.line[g_dis.cbpos + len]),
				&(g_line.line[g_dis.cbpos]),
				g_line.len - g_dis.cbpos);
	}
	ft_memmove(&(g_line.line[g_dis.cbpos]), string, len);
	g_line.len += len;
	g_dis.cbpos += len;
	update_line();
}

void		rl_delete(void)
{
	if (g_dis.cbpos < g_line.len && g_line.len > 0)
	{
		if (g_line.line[g_dis.cbpos] && g_dis.cbpos <= g_line.len)
		{
			ft_memmove(&(g_line.line[g_dis.cbpos]),
				&(g_line.line[g_dis.cbpos + 1]), g_line.len - g_dis.cbpos + 1);
			g_line.line[g_line.len + 1] = '\0';
			update_line();
			--g_line.len;
		}
		else if (g_dis.cbpos > 0)
		{
			g_line.line[g_dis.cbpos] = '\0';
			update_line();
			--g_line.len;
		}
	}
}

void		rl_backspace(void)
{
	if (g_dis.cbpos > 0)
	{
		cursor_l();
		if (g_line.line[g_dis.cbpos])
		{
			ft_memmove(&(g_line.line[g_dis.cbpos]),
				&(g_line.line[g_dis.cbpos + 1]), g_line.len - g_dis.cbpos + 1);
			g_line.line[g_line.len + 1] = '\0';
		}
		else
			g_line.line[g_dis.cbpos] = '\0';
		--g_line.len;
		update_line();
	}
}
