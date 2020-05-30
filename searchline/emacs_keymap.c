/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emacs_keymap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 20:29:21 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/30 21:37:02 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

char	*g_emacs_standard_keymap[] =
{
	rl_void,
	rl_home,
	cursor_l,
	kill_line,
	rl_eot,
	rl_end,
	cursor_r,
	rl_void,
	rl_backspace,
	autocomplete,
	rl_void,
	clear_eol,
	clear_scr,
	rl_void,
	history_down,
	rl_void,
	history_up,
	rl_void,
	hist_lookup,
	rl_void,
	rl_reversel,
	clear_befline,
	rl_void,
	cut_prev_wd,
	rl_ctrl_mode,
	clip_paste,
	rl_void,
	rl_void,
	rl_void,
	rl_void,
	rl_void,
	undo_last,
	[ ' ' ... '~' ] = rl_insert,
	rl_backspace
};

char	*g_emacs_ctlx_keymap[] =
{
	[ 0 ... 50 ] = rl_void,
	rl_delete,
	[ 52 ... 64 ] = rl_void,
	history_up,
	history_down,
	cursor_r,
	cursor_l,
	rl_void,
	rl_end,
	rl_void,
	rl_home,
	[ 73 ... 84 ] = rl_void,
	cursor_u,
	cursor_d,
	wd_right,
	wd_left,
	[ 89 ... 127 ] = rl_void,
};

char	*g_emacs_meta_keymap[] =
{
	[ 0 ... 97 ] = rl_void,
	wd_left,
	rl_void,
	cut_next_wd,
	rl_void,
	wd_right,
	[ 103 ... 115 ] = rl_void,
	swap_words,
	[ 117 ... 127 ] = rl_void,
};
