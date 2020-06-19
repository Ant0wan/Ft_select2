/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 19:04:22 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/19 11:12:32 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

# include <curses.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <term.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>

# include "libft.h"

# define NB_TERMS 11

# define DEFAULT	"\033[0m"
# define DIRECTORY	"\033[01;34m"
# define SYMLINK	"\033[01;36m"
# define PIPE		"\033[33m"
# define SOCKET		"\033[01;35m"
# define BLOCK_DEVICE	"\033[01;33m"
# define CHAR_DEVICE	"\033[01;33m"
# define EXECUTABLE	"\033[01;32m"
# define DOOR		"\033[01;35m"
# define SETUID		"\033[37;41m"
# define SETGID		"\033[30;43m"
# define STICKY		"\033[37;44m"
# define OTHER_WRITABLE	"\033[34;42m"
# define OW_STICKY	"\033[30;42m"
# define CA		"\033[30;41m"

# define SELECT 0
# define COMMAN 1
# define SEARCH 2

#define UNDERL "\033[4m"
#define HIGHLI "\033[7m"
#define BFIELD "\033[40;38;5;82m"
#define RESFID "\033[30;48;5;82m"
#define GRHELP "\033[37;40;5m"
#define GRMODE "\033[37;40;2m"
#define SEAERR "\033[97;41m"
#define DIMCOL "\033[37;40;2m\033[38;5;162m"

#define ARLE "◄"
#define ARRI "►"

#define ERR_TERM "Terminal capabilities insuficient for program use.\n"
#define ERR_WINS "Something went wrong in getting window size. ioctl(2): failed.\n"

#define NEED_ARG "ft_select requires at least one argument.\n\nUsage:\t./ft_select ARG...\n"

union					u_buffer
{
	unsigned long	value;
	char			buf[sizeof(unsigned long)];
};

struct	s_termcaps
{
	char	*cl;
	char	*ce;
	char	*vs;
	char	*vi;
	char	*us;
	char	*af;
	char	*ab;
	char	*cm;
	char	*me;
	char	*ti;
	char	*te;
};

struct	s_element
{
	struct s_element	*next;
	struct s_element	*previous;
	char			*arg;
	int			len;
	struct stat		st;
	int			selected;
	char			*color;
	int			c;
	int			r;
	int			c_width;
	int			page;
};

struct s_keymap
{
	void	(*std[128])();
	void	(*ctrl[128])();
	void	(*meta[128])();
};

struct s_sort
{
	struct s_sort	*next;
	struct s_sort	*prev;
	char		*name;
	int		(*fcmp)();
};

struct	s_select
{
	char			*ttyname;
	int			fd;
	char			*term;
	char			*tc_string[NB_TERMS];
	struct termios		termios_backup;
	struct termios		termios_select;
	struct s_termcaps	termcaps;
	int			dumb_mode;
	struct winsize		win;
	int			no_refresh;
	struct s_element	*elements;
	char			*line;
	int			mode;
	struct s_keymap		select_keymap;
	struct s_keymap		cmd_keymap;
	struct s_keymap		search_keymap;
	struct s_sort		*sort;
	int			frame_enabled;
	int			bar_enabled;
	int			help_enabled;
	int			search_error;
	char			*search_line;
	int			sl_size;
	int			sl_len;
	int			sl_cpos;
	struct s_element	*suggestion;
	int			psum;
	struct s_element	*cursor;
};

union u_buffer			read_key(void);
int     output(int c);
void	set_terminal(struct s_select *data);
void	unset_terminal(struct s_select *data);
void    data_static_method(struct s_select *set, struct s_select **get);
void		end_pgm(int sig);
void    fill_elements(struct s_select *data, int argc, char **argv);
char    *get_color(struct stat *st);
void    free_data(struct s_select **data);
void    free_elements(struct s_element *element);
void	bar(struct s_select *data);
void	frame(struct s_select *data);
void	display_elements(struct s_select *data);
void	display(struct s_select *data);
void	set_bar_color(struct s_select *data);
void		set_signals(void);
void            termsize(struct s_select *data);
void    placendisplay(int col, int row, struct s_element *l, struct s_select *data);
int     actions(struct s_select *data);
void    init_keymaps(struct s_select *data);
void	set_command_mode(struct s_select *data, union u_buffer input);
void	set_select_mode(struct s_select *data);
void	set_search_mode(struct s_select *data, union u_buffer input);
void	quit(struct s_select *data, union u_buffer input);
int     isstdkey(int c);
int	isctrlkey(union u_buffer c);
int	mvctrlkey(union u_buffer c);
int     isprintchr(int c);
int	enter_rc(union u_buffer c);
int	ismetachar(union u_buffer c);
void    init_sort_list(struct s_select *data);
void	sort(struct s_select *data);
void    left_sort_mode(struct s_select *data, union u_buffer input);
void    right_sort_mode(struct s_select *data, union u_buffer input);
void	ft_merge_sort(struct s_element **e, struct s_select *data);
void    fcompare(struct s_select *data, struct s_element **e1, struct s_element **e2, struct s_element **h);
int	alpha_compare(struct s_element *e1, struct s_element *e2);
int	size_compare(struct s_element *e1, struct s_element *e2);
int	time_compare(struct s_element *e1, struct s_element *e2);
int	type_compare(struct s_element *e1, struct s_element *e2);
int	uid_compare(struct s_element *e1, struct s_element *e2);
void		searchline(struct s_select *data);
void    page(struct s_select *data);
void	cursor_prev(struct s_select *data);
void	cursor_next(struct s_select *data);
void	select_it(struct s_select *data);
void	next_page(struct s_select *data);
void	prev_page(struct s_select *data);
void    go_right(struct s_select *data);
void    go_left(struct s_select *data);
void	go_home(struct s_select *data);
void    del_cursor_element(struct s_select *data);
void    del_one(struct s_select *data);
void	display_selection(struct s_select *data);
void	display_page(struct s_select *data);

#endif
