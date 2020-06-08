/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 19:04:22 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/07 23:45:31 by abarthel         ###   ########.fr       */
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

union					u_buffer
{
	unsigned long	value;
	char			buf[sizeof(unsigned long)];
};

struct	s_termcaps
{
	char	*cl; //0 clear all screen
	char	*ce; //1 clear end of line
	char	*vs; //2 cursor visible
	char	*vi; //3 cursor not visible
	char	*us; //4 underline
	char	*af; //5 font color
	char	*ab; //6 background color
	char	*cm; //7 move position
	char	*me; //8 reset colors
	char	*ti; //9 Enable full screen
	char	*te; //10 Disable full screen
};

struct	s_element
{
	struct s_element	*next;
	struct s_element	*previous;
	char			*arg; // No free
	int			len;
	struct stat		st;
	int			selected;
	char			*color; // No free
	int			page; // If not 0 this is the first element of the page having the page nb
	int			c_width; // column width if first element of the column
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
	char			*term; // No free
	char			*tc_string[NB_TERMS]; // No free
	struct termios		termios_backup; // No free
	struct termios		termios_select; // No free
	struct s_termcaps	termcaps; // No free
	int			dumb_mode; // Set true is all termcaps are not available
	struct winsize		win; // Use to get window size
	int			no_refresh; // Set to 0 if dis needed, 1 if last key executed none
	struct s_element	*elements; // linked list of elements
	char			*line; // Malloc
	int			mode; // 0. selection'escape', 1. control (change sort)':', 2. search '/'
	struct s_keymap		select_keymap;
	struct s_keymap		cmd_keymap;
	struct s_keymap		search_keymap;
	struct s_sort		*sort; // Sort mode selected
	int			frame_enabled; // 1 if frame can be displayed else 0
	int			bar_enabled; // 1 if bar can be displayed else 0
	int			help_enabled; // If too win too small, help is not displayed
	int			search_error; // 1:error, 0:no error
	char			*search_line; // line input for search loop
	int			sl_size; //  buffer of search_line
	int			sl_len; // len of line
	int			sl_cpos; // Cursor position on the line
	struct s_element	*suggestion; // element suggested for completion
	int			pnb; // page number the user is at
	int			psum; // total nb of pages needed
	struct s_element	*cursor; // element the user is underlining
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
void	set_select_mode(struct s_select *data);//, union u_buffer input);
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
void    del_cursor_element(struct s_select *data);


void	del_one(struct s_element *element);

#endif
