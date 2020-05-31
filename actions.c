/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:59:02 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 14:54:20 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "searchline.h"

int	actions(struct s_select *data)
{
	union u_buffer	input;

	input = read_key();
	//	ft_printf(">>%d,%d,%d,%d, %d, %d << ", input.buf[0], input.buf[1], input.buf[2], input.buf[3], input.buf[4], input.buf[5]);
	if (data->mode == SELECT)
	{
		if (enter_rc(input))
			return (0);
		else if (isstdkey(input.value))
			(data->select_keymap.std[input.value])(data, input);
		else if (isctrlkey(input))
			(data->select_keymap.ctrl[(int)input.buf[2]])(data, input);
	}
	else if (data->mode == COMMAN)
	{
		if (isstdkey(input.value))
			(data->cmd_keymap.std[input.value])(data, input);
		else if (isctrlkey(input))
			(data->cmd_keymap.ctrl[(int)input.buf[2]])(data, input);
	}
	else if (data->mode == SEARCH)
	{
		if (isstdkey(input.value))
			(data->search_keymap.std[input.value])(data, input);
		else if (isctrlkey(input))
		{
			if (mvctrlkey(input))
				input.buf[2] = input.buf[5] + 20;
			(data->search_keymap.ctrl[(int)input.buf[2]])(data, input);
		}
	}
	return (1);
}
