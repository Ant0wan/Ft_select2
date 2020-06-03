/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 17:51:21 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/03 23:34:26 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchline.h"

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
		ft_printf("%s%.*s%s", l->color, data->win.ws_col - w_frame * 2, l->arg, DEFAULT);
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
	tputs(tgoto(data->termcaps.cl, 0, 0), 1, output);
	frame(data);
	display_elements(data);
	page(data);
	bar(data);
}
