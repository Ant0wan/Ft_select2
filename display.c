/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 17:51:21 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/03 11:23:56 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchline.h"

void	display_elements(struct s_select *data)
{
	struct s_element	*l;
	int	i;
	int	j;
	int	width;

	tputs(tgoto(data->termcaps.cm, 1, 1), 1, output);
	l = data->elements;
	i = 0;
	j = 0;
	width = 0;
	while (l)
	{
		tputs(tgoto(data->termcaps.cm, 1 + j, 1 + i), 1, output);
		ft_printf("%s%s%s", l->color, l->arg, DEFAULT);
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
	bar(data);
}
