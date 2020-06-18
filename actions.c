/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:59:02 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/18 22:38:10 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "searchline.h"

int	select_input(struct s_select *data)
{
	union u_buffer	input;

	input = read_key();
	if (enter_rc(input))
		return (1);
	else if (isstdkey(input.value))
		(data->select_keymap.std[input.value])(data, input);
	else if (isctrlkey(input))
		(data->select_keymap.ctrl[(int)input.buf[2]])(data, input);
	return (0);
}

int	command_input(struct s_select *data)
{
	union u_buffer	input;

	input = read_key();
	if (enter_rc(input))
		set_select_mode(data);
	else if (isstdkey(input.value))
		(data->cmd_keymap.std[input.value])(data, input);
	else if (isctrlkey(input))
		(data->cmd_keymap.ctrl[(int)input.buf[2]])(data, input);
	return (0);
}

int	search_input(struct s_select *data)
{
	tputs(data->termcaps.vs, 1, output);
	searchline(data);
	tputs(data->termcaps.vi, 0, output);
	set_select_mode(data);
	return (0);
}

int	actions(struct s_select *data)
{
	if (data->mode == SELECT)
		return (select_input(data));
	else if (data->mode == COMMAN)
		return (command_input(data));
	else if (data->mode == SEARCH)
		return (search_input(data));
	return (1);
}
