/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:59:02 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/07 23:46:06 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "searchline.h"

static void	none(struct s_select *data, union u_buffer input)
{
	data->no_refresh = 1;
	(void)input;
	return;
}

void	set_command_keymap(struct s_select *data)
{
	// set select binding
	data->select_keymap.ctrl[65] = &cursor_prev; // prev element up
	data->select_keymap.ctrl[66] = &cursor_next; // next element down
	data->select_keymap.ctrl[51] = &del_cursor_element;
	data->select_keymap.std[27] = &quit;
	data->select_keymap.std[' '] = &select_it;
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
