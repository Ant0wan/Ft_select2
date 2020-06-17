/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 17:51:21 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/17 19:45:07 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchline.h"

static void	display_element(struct s_select *data, struct s_element *l)
{
	if (l == data->cursor)
	{
		if (!l->selected)
		{
			ft_dprintf(data->fd, "%s%s%.*s%s", l->color, UNDERL, l->c_width, l->arg, DEFAULT);
		//	ft_dprintf(data->fd, "%s%s%d%s", l->color, UNDERL, l->c, DEFAULT);
		}
		else
		{
			ft_dprintf(data->fd, "%s%s%.*s%s", HIGHLI, UNDERL, l->c_width, l->arg, DEFAULT);
		//	ft_dprintf(data->fd, "%s%s%d%s", HIGHLI, UNDERL, l->c, DEFAULT);
		}
	}
	else
	{
		if (!l->selected)
		{
			ft_dprintf(data->fd, "%s%.*s%s", l->color, l->c_width, l->arg, DEFAULT);
		//	ft_dprintf(data->fd, "%s%d%s", l->color, l->c, DEFAULT);
		}
		else
		{
			ft_dprintf(data->fd, "%s%.*s%s", "\e[7m", l->c_width, l->arg, DEFAULT);
		//	ft_dprintf(data->fd, "%s%d%s", "\e[7m", l->c, DEFAULT);
		}
	}
}

void	display_page(struct s_select *data)
{
	struct s_element *e;

//	e = data->cursor;
	e = data->elements;
//	while (e->previous)
//	{
//		if (e->page != e->previous->page)
//			break;
//		else
//			e = e->previous;
//	}
	while (e)
	{
		tputs(tgoto(data->termcaps.cm, e->c, e->r), 1, output);
		display_element(data, e);
//		if (e->next && e->next->page != e->page)
//			break;
		e = e->next;
	}
}

void	display(struct s_select *data)
{
	frame(data);
	bar(data);
	page(data);
}
