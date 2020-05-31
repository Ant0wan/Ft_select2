/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:13:39 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 17:12:45 by abarthel         ###   ########.fr       */
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

void	cut_prev_wd(struct s_select *data)
{
	int	start;
	int	l;

	if (data->sl_cpos != 0)
	{
		start = data->sl_cpos;
		while (start && data->search_line[start - 1] == ' ')
			--start;
		while (start && data->search_line[start - 1] != ' ')
			--start;
		l = data->sl_cpos - start;
		ft_memmove(&(data->search_line[start]),
		&(data->search_line[data->sl_cpos]), data->sl_len - data->sl_cpos);
		data->sl_len -= l;
		ft_bzero(&(data->search_line[data->sl_len]), l);
		data->sl_cpos = start;
		bar(data);
	}
}

void    rl_reversel(struct s_select *data)
{
	char	c;

	if (data->sl_len > 1)
	{
		if (data->sl_len > 1 && data->sl_cpos == data->sl_len)
		{
			c = data->search_line[data->sl_cpos - 1];
			data->search_line[data->sl_cpos - 1] = data->search_line[data->sl_cpos - 2];
			data->search_line[data->sl_cpos - 2] = c;
			bar(data);
		}
		else if (data->sl_cpos > 0)
		{
			c = data->search_line[data->sl_cpos];
				data->search_line[data->sl_cpos] = data->search_line[data->sl_cpos - 1];
			data->search_line[data->sl_cpos - 1] = c;
			cursor_r(data);
		}
	}
}
