/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 17:51:21 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/11 16:59:47 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchline.h"

void	display_element(struct s_select *data, struct s_element *l, int w_frame)
{
	if (l == data->cursor)
	{
		if (!l->selected)
		{
			ft_dprintf(data->fd, "%s%s%.*s%s", l->color, UNDERL,
				data->win.ws_col - w_frame * 2, l->arg, DEFAULT);
		}
		else
		{
			ft_dprintf(data->fd, "%s%s%.*s%s", HIGHLI, UNDERL,
				data->win.ws_col - w_frame * 2, l->arg, DEFAULT);
		}
	}
	else
	{
		if (!l->selected)
		{
			ft_dprintf(data->fd, "%s%.*s%s", l->color,
				data->win.ws_col - w_frame * 2, l->arg, DEFAULT);
		}
		else
		{
			ft_dprintf(data->fd, "%s%.*s%s", "\e[7m",
				data->win.ws_col - w_frame * 2, l->arg, DEFAULT);
		}
	}
}

void	display_elements(struct s_select *data)
{
	int	w_frame;
	struct s_element	*l;
	int	i;
	int	j;
	int	width;

	if (data->frame_enabled)
		w_frame = 1;
	else
		w_frame = 0;
	l = data->elements;
	i = 0;
	j = 0;
	width = 0;
	while (l)
	{
		tputs(tgoto(data->termcaps.cm, w_frame + j, w_frame + i), 1, output);

		display_element(data, l, w_frame);

		if (l->len > width)
			width = l->len + 1;
		l = l->next;
		++i;
		if (i >= data->win.ws_row - 3)
		{
			i = 0;
			j += width;
		}
	}
}

void	display(struct s_select *data)
{
	frame(data);
	page(data);

	bar(data);
}
