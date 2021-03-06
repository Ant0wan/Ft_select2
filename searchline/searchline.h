/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchline.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 10:20:12 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/23 10:54:01 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHLINE_H
# define SEARCHLINE_H

# include "../select.h"

# define READLINE_DEFAULT_BUFFER_SIZE 256

void	insert_text(struct s_select *data, const char *string, int len);
void	init_line_buffer(struct s_select *data);

/*
** Set binding of the search bar
*/

void	set_search_std_insertion_keymap(struct s_select *data);
void	set_search_std_keymap(struct s_select *data);
void	set_search_ctrl_keymap(struct s_select *data);
void	set_search_meta_keymap(struct s_select *data);

/*
** All key bind functions
*/

void	rl_insert(struct s_select *data, int c);
void	paste_via_input(struct s_select *data, unsigned long v);
void	cursor_l(struct s_select *data);
void	cursor_r(struct s_select *data);
void	rl_home(struct s_select *data);
void	rl_end(struct s_select *data);
void	rl_delete(struct s_select *data);
void	wd_left(struct s_select *data);
void	wd_right(struct s_select *data);
void	rl_backspace(struct s_select *data);
void	clear_eol(struct s_select *data);
void	clear_befline(struct s_select *data);
void	clear_line(struct s_select *data);
void	cut_prev_wd(struct s_select *data);
void	rl_reversel(struct s_select *data);
void	disp_sug(struct s_select *data);
void	check_occur(struct s_select *data);
void	tab_autocomp(struct s_select *data);

#endif
