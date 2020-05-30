/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:21:06 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/30 21:41:35 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H

# include <signal.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <fcntl.h>

# include "libft.h"
# include "ft_stack.h"
# include "bind.h"
# include "keymaps.h"
# include "input.h"
# include "terminal.h"
# include "utils.h"
# include "display.h"
# include "line.h"
# include "tty.h"

# ifndef SIGWINCH
#  define SIGWINCH 28
# endif

# define READLINE_DEFAULT_BUFFER_SIZE 256

void	insert_text(const char *string, int len);
void	clear_line(void);

void	cut_prev_wd(void);
void	cut_next_wd(void);
void	clear_befline(void);
void	paste_via_input(unsigned long v);
void	clip_paste(void);
void	wd_right(void);
void	wd_left(void);
void	clear_eol(void);
void	autocomplete(void);
void	rl_home(void);
void	rl_void(void);
void	rl_end(void);
void	rl_eot(void);
void	rl_delete(void);
void	rl_backspace(void);
void	rl_insert(int c);
void	cursor_l(void);
void	cursor_r(void);
void	history_up(void);
void	history_down(void);
void    rl_reversel(void);
void	swap_words(void);
void	beg_next_wd(void);
void	beg_next_alnum(void);
void	end_next_alnum(void);
void	end_next_wd(void);
void	beg_last_alnum(void);
void	goto_chr_right(void);
void	goto_chr_left(void);
void	goto_pchr_right(void);
void	goto_pchr_left(void);
void	last_goto(void);
void	insert_mode_next(void);
void	insert_mode_last(void);
void	insert_mode_first(void);
void	replace_wd(void);
void	replace_text(const char *string, int len);
void	replace_mode(void);
void	l_expand(void);


void	init_line_buffer(void);
void	update_line(void);

int		output(int c);
int		rl_toupper(int c);
int		rl_tolower(int c);
int		isoctal(int c);
int		isxdigit(int c);
int		hexvalue(int c);
int		metachar(int c);
int		isprintchr(int c);
int		isstdkey(int c);
int		ismetachar(union u_buffer c);
int		isctrlkey(union u_buffer c);
int		mvctrlkey(union u_buffer c);
int		enter_rc(union u_buffer c);
int		test_c_value(union u_buffer c);

#endif
