/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 11:23:23 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/17 12:56:12 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int	output(int c)
{
	struct s_select	*data;

	data_static_method(NULL, &data);
	if (write(data->fd, &c, sizeof(c)) != -1)
		return ((unsigned char)c);
	else
		return (EOF);
}

void	placendisplay(int col, int row, struct s_element *l, struct s_select *data)
{
        tputs(tgoto(data->termcaps.cm , col, row), 1, output);
        write(data->fd, l->arg, l->len);
}
