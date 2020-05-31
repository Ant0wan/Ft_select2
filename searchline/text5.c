/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:13:39 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 16:51:11 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchline.h"

void	clear_befline(struct s_select *data)
{
	if (data->sl_cpos > 0)
	{
		data->sl_len -= data->sl_cpos;
		ft_memmove(data->search_line, &(data->search_line[data->sl_cpos]), data->sl_cpos);
		ft_bzero(&(data->search_line[data->sl_len]), data->sl_cpos);
		data->sl_cpos = 0;
		rl_home(data);
		bar(data);
	}
}
/*
void	cut_prev_wd(void)
{
	int start;

	if (g_dis.cbpos != 0)
	{
		if (g_clip.str != NULL)
			free(g_clip.str);
		start = g_dis.cbpos;
		while (start && g_line.line[start - 1] == ' ')
			--start;
		while (start && g_line.line[start - 1] != ' ')
			--start;
		g_clip.l = g_dis.cbpos - start;
		g_clip.str = ft_strndup(&(g_line.line[start]), g_clip.l);
		ft_memmove(&(g_line.line[start]),
		&(g_line.line[g_dis.cbpos]), g_line.len - g_dis.cbpos);
		g_line.len -= g_clip.l;
		ft_bzero(&(g_line.line[g_line.len]), g_clip.l);
		g_dis.cbpos = start;
		bar(data);
	}
}

void    rl_reversel(void)
{
	char c;

	if (g_line.len > 1)
	{
		if (g_line.len > 1 && g_dis.cbpos == g_line.len)
		{
			c = g_line.line[g_dis.cbpos - 1];
			g_line.line[g_dis.cbpos - 1] = g_line.line[g_dis.cbpos - 2];
			g_line.line[g_dis.cbpos - 2] = c;
			bar(data);
		}
		else if (g_dis.cbpos > 0)
		{
			c = g_line.line[g_dis.cbpos];
				g_line.line[g_dis.cbpos] = g_line.line[g_dis.cbpos - 1];
			g_line.line[g_dis.cbpos - 1] = c;
			cursor_r();
		}
	}
}

void	cut_next_wd(void)
{
	int start;

	if (g_clip.str != NULL)
		free(g_clip.str);
	start = g_dis.cbpos;
	while (start < g_line.len && g_line.line[start] == ' ')
		++start;
	while (start < g_line.len && g_line.line[start] != ' ')
		++start;
	g_clip.l = start - g_dis.cbpos;
	g_clip.str = ft_strndup(&(g_line.line[g_dis.cbpos]), g_clip.l);
	ft_memmove(&(g_line.line[g_dis.cbpos]), &(g_line.line[start]), g_line.len - start);
	g_line.len -= g_clip.l;
	ft_bzero(&(g_line.line[g_line.len]), g_clip.l);
	bar(data);
}*/
