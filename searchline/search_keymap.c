/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_keymap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 20:29:21 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 17:20:14 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchline.h"

void	set_search_std_insertion_keymap(struct s_select *data)
{
	int	i;

	i = ' ';
	while (i <= '~')
	{
		data->search_keymap.std[i] = &rl_insert;
		++i;
	}
}

void	set_search_std_keymap(struct s_select *data)
{
	(void)data;
	data->search_keymap.std[1] = &rl_home;
	data->search_keymap.std[2] = &cursor_l;
	data->search_keymap.std[5] = &rl_end;
	data->search_keymap.std[6] = &cursor_r;
	data->search_keymap.std[8] = &rl_backspace;
//	data->search_keymap.std[9] = &autocomplete;
	data->search_keymap.std[11] = &clear_eol;
	data->search_keymap.std[12] = &clear_line;
	data->search_keymap.std[20] = &rl_reversel;
	data->search_keymap.std[21] = &clear_befline;
	data->search_keymap.std[23] = &cut_prev_wd;
	data->search_keymap.std[127] = &rl_backspace;
}

void	set_search_ctrl_keymap(struct s_select *data)
{
	data->search_keymap.ctrl[51] = &rl_delete;
	data->search_keymap.ctrl[67] = &cursor_r;
	data->search_keymap.ctrl[68] = &cursor_l;
	data->search_keymap.ctrl[70] = &rl_end;
	data->search_keymap.ctrl[72] = &rl_home;
	data->search_keymap.ctrl[87] = &wd_right;
	data->search_keymap.ctrl[88] = &wd_left;
}

void	set_search_meta_keymap(struct s_select *data)
{
	data->search_keymap.meta[98] = &wd_left;
	data->search_keymap.meta[102] = &wd_right;
}
