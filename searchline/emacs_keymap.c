/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emacs_keymap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 20:29:21 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 11:01:41 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchline.h"

char	*g_emacs_standard_keymap[] =
{
	[1] = rl_home,
	[2] = cursor_l,
	[3] = kill_line,
	[4] = rl_eot,
	[5] = rl_end,
	[6] = cursor_r,
	[8] = rl_backspace,
	[9] = autocomplete,
	[11] = clear_eol,
	[12] = clear_scr,
	[14] = history_down,
	[16] = history_up,
	[18] = hist_lookup,
	[20] = rl_reversel,
	[21] = clear_befline,
	[23] = cut_prev_wd,
	[24] = rl_ctrl_mode,
	[25] = clip_paste,
	[31] = undo_last,
	[ ' ' ... '~' ] = rl_insert,
	[127] = rl_backspace
};

char	*g_emacs_ctlx_keymap[] =
{
	[ 0 ... 50 ] = rl_void,
	[51] = rl_delete,
	[ 52 ... 64 ] = rl_void,
	[65] = history_up,
	[66] = history_down,
	[67] = cursor_r,
	[68] = cursor_l,
	[69] = rl_void,
	[70] = rl_end,
	[71] = rl_void,
	[72] = rl_home,
	[ 73 ... 84 ] = rl_void,
	[85] = cursor_u,
	[86] = cursor_d,
	[87] = wd_right,
	[88] = wd_left,
	[ 89 ... 127 ] = rl_void,
};

char	*g_emacs_meta_keymap[] =
{
	[ 0 ... 97 ] = rl_void,
	[98] = wd_left,
	[99] = rl_void,
	[100] = cut_next_wd,
	[101] = rl_void,
	[102] = wd_right,
	[ 103 ... 115 ] = rl_void,
	[116] = swap_words,
	[ 117 ... 127 ] = rl_void,
};
