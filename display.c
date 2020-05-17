/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 17:51:21 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/17 17:15:22 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	bar(struct s_select *data, struct s_element *l)
{
	tputs(tgoto(data->termcaps.cm, 0, data->win.ws_row), 1, output);
	ft_dprintf(data->fd, " %sName:%s\tSize: %ldBytes\tType: %s%s", "\033[93m", l->arg, l->st.st_size, "directory", DEFAULT);
}

void	frame(struct s_select *data)
{
	int	i;

	// get windows size to chekc limits
	ioctl(STDERR_FILENO, TIOCGWINSZ, &(data->win));

	// Draw frame corners
	tputs(tgoto(data->termcaps.cm, 0, 0), 1, output);
	ft_dprintf(data->fd, "┌");

	i = 0;
	while (++i < data->win.ws_col - 1)
		ft_dprintf(data->fd, "─");

	ft_dprintf(data->fd, "┐");

	i = 0;
	while (++i < data->win.ws_row - 2)
	{
		tputs(tgoto(data->termcaps.cm, 0, i), 1, output);
		ft_dprintf(data->fd, "│");
		tputs(tgoto(data->termcaps.cm, data->win.ws_col, i), 1, output);
		ft_dprintf(data->fd, "│");
	}

	tputs(tgoto(data->termcaps.cm, 0, data->win.ws_row - 2), 1, output);
	ft_dprintf(data->fd, "└");
	i = 0;
	while (++i < data->win.ws_col - 1)
		ft_dprintf(data->fd, "─");
	ft_dprintf(data->fd, "┘");
}

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
	frame(data);
	bar(data, data->elements);
	display_elements(data);
	sleep(2);
}
