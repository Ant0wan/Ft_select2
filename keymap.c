/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:59:02 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/18 15:39:02 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

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

	(void)data;
	while (1)
	{
		input = read_key();
		if (data->mode == SELECT)
		{
			if (isstdkey(input.value))
				(data->select_keymap.std[input.value])(data, input);
		}
		else if (data->mode == COMMAN)
		{
			(void)input;
		}
		else if (data->mode == SEARCH)
		{
			(void)input;
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
//	data->cmd_keymap.std[i] = &set_select_mode;
//	data->search_keymap.std[i] = &set_select_mode;
	data->select_keymap.std[':'] = &set_command_mode;
	data->select_keymap.std['/'] = &set_search_mode;
	data->cmd_keymap.std['/'] = &set_search_mode;
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
