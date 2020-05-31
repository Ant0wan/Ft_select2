/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:59:02 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 11:49:03 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "searchline.h"

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

int	actions(struct s_select *data)
{
	union u_buffer	input;

	while (1)
	{
		input = read_key();
	//	ft_printf(">>%d,%d,%d,%d, %d, %d << ", input.buf[0], input.buf[1], input.buf[2], input.buf[3], input.buf[4], input.buf[5]);
		if (data->mode == SELECT)
		{
			if (isstdkey(input.value))
				(data->select_keymap.std[input.value])(data, input);
			else if (isctrlkey(input))
			{
			//	if (mvctrlkey(input))
			//		input.buf[2] = input.buf[5] + 20;
				(data->select_keymap.ctrl[(int)input.buf[2]])(data, input);
			}
		}
		else if (data->mode == COMMAN)
		{
			if (isstdkey(input.value))
				(data->cmd_keymap.std[input.value])(data, input);
			else if (isctrlkey(input))
			{
			//	if (mvctrlkey(input))
			//		input.buf[2] = input.buf[5] + 20;
				(data->cmd_keymap.ctrl[(int)input.buf[2]])(data, input);
			}
		}
		else if (data->mode == SEARCH)
		{
			if (isstdkey(input.value))
				(data->search_keymap.std[input.value])(data, input);
			else if (isctrlkey(input))
			{
			//	if (mvctrlkey(input))
			//		input.buf[2] = input.buf[5] + 20;
				(data->search_keymap.ctrl[(int)input.buf[2]])(data, input);
			}
		}
	}
	return (0);
}

static void	none(struct s_select *data, union u_buffer input)
{
	(void)data;
	(void)input;
	return;
}

void	set_command_keymap(struct s_select *data)
{
	// set select binding
	data->select_keymap.std[27] = &quit;
	data->select_keymap.std[':'] = &set_command_mode;
	data->select_keymap.std['/'] = &set_search_mode;

	// set cmd binding
	data->cmd_keymap.ctrl[67] = &right_sort_mode;
	data->cmd_keymap.ctrl[68] = &left_sort_mode;
	data->cmd_keymap.std[27] = &set_select_mode;

	// set search binding
	set_search_std_insertion_keymap(data);
	set_search_std_keymap(data);
	set_search_ctrl_keymap(data);
	set_search_meta_keymap(data);
}

void	init_keymaps(struct s_select *data)
{
	int	i;

	i = 127;
	while (i > -1)
	{
		data->select_keymap.std[i] = &none;
		data->select_keymap.ctrl[i] = &none;
		data->select_keymap.meta[i] = &none;
		data->cmd_keymap.std[i] = &none;
		data->cmd_keymap.ctrl[i] = &none;
		data->cmd_keymap.meta[i] = &none;
		data->search_keymap.std[i] = &none;
		data->search_keymap.ctrl[i] = &none;
		data->search_keymap.meta[i] = &none;
		--i;
	}
	set_command_keymap(data);
}
