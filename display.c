/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 17:51:21 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/17 11:04:26 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	frame(struct s_select *data)
{
//	int	i;

	// get windows size to chekc limits
//	ioctl(STDERR_FILENO, TIOCGWINSZ, &(data->win));
	// Draw frame corners
	(void)data;
	tputs(tgoto(tgetstr("cl", NULL), 0, 0), 1, putchar);
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, putchar);
//	ft_printf("beg");
//	ft_printf("┌");

//	i = 0;
//	while (++i < data->win.ws_col - 1)
//		ft_printf("─");

//	ft_printf("┐");
//	tputs(tgoto(tgetstr("cm", NULL), data->win.ws_col, 0), 1, putchar);
//
//	ft_printf("│");
//
//	tputs(tgoto(tgetstr("cm", NULL), 0, data->win.ws_row), 1, putchar);
//	ft_printf("└");
//
//	i = 0;
//	while (++i < data->win.ws_col - 1)
//		ft_printf("─");
//
//	tputs(tgoto(tgetstr("cm", NULL), data->win.ws_col, data->win.ws_row), 1, putchar);
//	ft_printf("┘");
}

void	display(struct s_select *data)
{
	struct s_element	*l;

	l = data->elements;
	frame(data);
	while (l)
	{
		ft_printf("%s%s%s\t", l->color , l->arg, DEFAULT);
		l = l->next;
	}
	sleep(4);
}
