/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 17:51:21 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/16 18:04:45 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchline.h"

static void	display_element(struct s_select *data, struct s_element *l, int w_frame)
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

static int	display_column(struct s_select *data, struct s_element **l, int offset)
{
	int	next_offset;
	int	w_frame;
	int	line;

	if (data->frame_enabled)
		w_frame = 1;
	else
		w_frame = 0;
	next_offset = 0;
	if (*l && (*l)->c_width)
	{
		next_offset = (*l)->c_width + 1;
		tputs(tgoto(data->termcaps.cm, offset + w_frame, w_frame), 1, output);
		display_element(data, *l, w_frame);
		*l = (*l)->next;
	}
	else if (!(*l)->next)
		return (-1);
	line = 1;
	while (*l && (*l)->next && !(*l)->next->c_width)
	{
		tputs(tgoto(data->termcaps.cm, offset + w_frame, w_frame + line), 1, output);
		display_element(data, *l, w_frame);
		*l = (*l)->next;
	}
	return (next_offset);
}

void	display_elements(struct s_select *data)
{
	struct s_element	*l;
	int			offset;

	offset = 0;
	l = data->elements;
	while (l)
	{
		offset = display_column(data, &l, offset);
		l = l->next;
	}
}

void	display(struct s_select *data)
{
	frame(data);
	page(data);

	bar(data);
}
