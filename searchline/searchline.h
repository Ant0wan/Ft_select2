/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchline.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 10:20:12 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 12:42:12 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHLINE_H
# define SEARCHLINE_H

# include "../select.h"

# define READLINE_DEFAULT_BUFFER_SIZE 256

void	insert_text(struct s_select *data, const char *string, int len);
void	init_line_buffer(struct s_select *data);
void	update_line(struct s_select *data);

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

void    rl_insert(struct s_select *data, int c);
void	paste_via_input(struct s_select *data, unsigned long v);
void	cursor_l(struct s_select *data);
void	cursor_r(struct s_select *data);
void    rl_home(struct s_select *data);

#endif
