/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:48:35 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/07 15:35:11 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	set_select_mode(struct s_select *data)//, union u_buffer input)
{
	static struct s_sort	*lastsort;

	if (lastsort == data->sort)
		data->no_refresh = 1;
	data->mode = SELECT;
	data->search_error = 0;
	sort(data);
}

void	quit(struct s_select *data, union u_buffer input)
{
	(void)data;
	(void)input;
	end_pgm(-128);
}

void	cursor_prev(struct s_select *data)
{
	if (data->cursor->previous)
	{
		data->cursor = data->cursor->previous;
		display_elements(data);
	}
	data->no_refresh = 1;
}

void	cursor_next(struct s_select *data)
{
	if (data->cursor->next)
	{
		data->cursor = data->cursor->next;
		display_elements(data);
	}
	data->no_refresh = 1;
}
