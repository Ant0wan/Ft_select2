/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:16:27 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 15:45:42 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchline.h"

void		init_line_buffer(struct s_select *data)
{
	data->sl_size = 512;
	data->search_line = (char*)malloc(sizeof(char) * data->sl_size);
	ft_bzero(data->search_line, data->sl_size);
	data->sl_cpos = 0;
	data->sl_len = 0;
}

void		l_expand(struct s_select *data)
{
	char	*new;
	size_t	lold;

	lold = data->sl_size;
	data->sl_size = lold * 2;
	new = (char*)malloc(sizeof(char) * data->sl_size);
	ft_bzero(new, lold * 2);
	ft_strncpy(new, data->search_line, lold);
	free(data->search_line);
	data->search_line = new;
}

void		insert_text(struct s_select *data, const char *string, int len)
{
	while (len + data->sl_len >= data->sl_size)
		l_expand(data);
	if (data->sl_cpos < data->sl_len)
	{
		ft_memmove(&(data->search_line[data->sl_cpos + len]), &(data->search_line[data->sl_cpos]), data->sl_len - data->sl_cpos);
	}
	ft_memmove(&(data->search_line[data->sl_cpos]), string, len);
	data->sl_len += len;
	data->sl_cpos += len;
	bar(data);
}

void		rl_delete(struct s_select *data)
{
	if (data->sl_cpos < data->sl_len && data->sl_len > 0)
	{
		if (data->search_line[data->sl_cpos] && data->sl_cpos <= data->sl_len)
		{
			ft_memmove(&(data->search_line[data->sl_cpos]),
				&(data->search_line[data->sl_cpos + 1]), data->sl_len - data->sl_cpos + 1);
			data->search_line[data->sl_len + 1] = '\0';
			bar(data);
			--data->sl_len;
		}
		else if (data->sl_cpos > 0)
		{
			data->search_line[data->sl_cpos] = '\0';
			bar(data);
			--data->sl_len;
		}
	}
}

void		rl_backspace(struct s_select *data)
{
	if (data->sl_cpos > 0)
	{
		cursor_l(data);
		if (data->search_line[data->sl_cpos])
		{
			ft_memmove(&(data->search_line[data->sl_cpos]),
				&(data->search_line[data->sl_cpos + 1]), data->sl_len - data->sl_cpos + 1);
			data->search_line[data->sl_len + 1] = '\0';
		}
		else
			data->search_line[data->sl_cpos] = '\0';
		--data->sl_len;
		bar(data);
	}
}
