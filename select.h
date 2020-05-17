/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 19:04:22 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/17 12:51:10 by abarthel         ###   ########.fr       */
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

struct	s_termcaps
{
	char	*cd; //0 wipe
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
	int			underlined;
	char			*color; // No free
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
	struct s_element	*elements; // linked list of elements
};

union					u_buffer
{
	unsigned long	value;
	char			buf[sizeof(unsigned long)];
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

void	display(struct s_select *data);

void		set_signals(void);
void    placendisplay(int col, int row, struct s_element *l, struct s_select *data);

#endif
