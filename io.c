/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 11:23:23 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 14:52:48 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "searchline.h"

int	output(int c)
{
	struct s_select	*data;

	data_static_method(NULL, &data);
	if (write(data->fd, &c, sizeof(c)) != -1)
		return ((unsigned char)c);
	else
		return (EOF);
}

union u_buffer	read_key(void)
{
	union u_buffer	buffer_u;
	int		ret;

	buffer_u.value = 0;
	ret = read(STDIN_FILENO, buffer_u.buf, sizeof(buffer_u.buf));
	if (ret == -1)
		buffer_u.value = -1;
	return (buffer_u);
}

/*
void	placendisplay(int col, int row, struct s_element *l, struct s_select *data)
{
        tputs(tgoto(data->termcaps.cm , col, row), 1, output);
        write(data->fd, l->arg, l->len);
}*/

