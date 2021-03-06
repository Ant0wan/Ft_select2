/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:59:02 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/18 23:38:54 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "searchline.h"

static void	none(struct s_select *data)
{
	data->no_refresh = 1;
}

void		set_select_keymap(struct s_select *data)
{
	data->select_keymap.ctrl[51] = &del_cursor_element;
	data->select_keymap.ctrl[53] = &prev_page;
	data->select_keymap.ctrl[54] = &next_page;
	data->select_keymap.ctrl[65] = &cursor_prev;
	data->select_keymap.ctrl[66] = &cursor_next;
	data->select_keymap.ctrl[67] = &go_right;
	data->select_keymap.ctrl[68] = &go_left;
	data->select_keymap.ctrl[72] = &go_home;
	data->select_keymap.std[27] = &quit;
	data->select_keymap.std[' '] = &select_it;
	data->select_keymap.std[':'] = &set_command_mode;
	data->select_keymap.std['/'] = &set_search_mode;
	data->select_keymap.std[127] = &del_cursor_element;
}

void		set_command_keymap(struct s_select *data)
{
	data->cmd_keymap.ctrl[67] = &right_sort_mode;
	data->cmd_keymap.ctrl[68] = &left_sort_mode;
	data->cmd_keymap.std[27] = &set_select_mode;
	set_search_std_insertion_keymap(data);
	set_search_std_keymap(data);
	set_search_ctrl_keymap(data);
	set_search_meta_keymap(data);
}

void		init_keymaps(struct s_select *data)
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
	set_select_keymap(data);
}
