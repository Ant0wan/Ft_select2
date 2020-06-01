/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 13:17:43 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/01 18:23:01 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		termsize(struct s_select *data)
{
	if (ioctl(STDERR_FILENO, TIOCGWINSZ, &(data->win)) == -1)
	{
		ft_dprintf(STDERR_FILENO, ERR_WINS);
		end_pgm(-126);
	}
}

static void	set_termcaps(struct s_select *data)
{
	if (!(data->termcaps.cl = tgetstr("cl", NULL))
		|| !(data->termcaps.ce = tgetstr("ce", NULL))
		|| !(data->termcaps.vs = tgetstr("vs", NULL))
		|| !(data->termcaps.vi = tgetstr("vi", NULL))
		|| !(data->termcaps.us = tgetstr("us", NULL))
		|| !(data->termcaps.af = tgetstr("AF", NULL))
		|| !(data->termcaps.ab = tgetstr("AB", NULL))
		|| !(data->termcaps.cm = tgetstr("cm", NULL))
		|| !(data->termcaps.me = tgetstr("me", NULL))
		|| !(data->termcaps.ti = tgetstr("ti", NULL))
		|| !(data->termcaps.te = tgetstr("te", NULL)))
			data->dumb_mode = 1;
}

void	set_terminal(struct s_select *data)
{
	if (isatty(STDOUT_FILENO))
	{
		data->ttyname = ttyname(STDIN_FILENO);
		if (data->ttyname)
			data->fd = open(data->ttyname, O_RDWR);
		if (data->fd == -1)
			exit(2);
		data->term = getenv("TERM");
		if (!data->term)
			data->term = "dumb";
		if (tgetent(NULL, data->term) != 1)
		{
			write(STDERR_FILENO, ERR_TERM, ft_strlen(ERR_TERM));
			exit(2);
		}
	}
	else
		exit(1);
	set_termcaps(data);
	if (data->dumb_mode) // Should be removed once dumb_mode is handled
	{
		write(STDERR_FILENO, ERR_TERM, ft_strlen(ERR_TERM));
		exit(2);
	}
	tcgetattr(STDOUT_FILENO, &(data->termios_backup));
	tcgetattr(STDOUT_FILENO, &(data->termios_select));
	data->termios_select.c_lflag &= ~(ICANON | ECHO);
	data->termios_select.c_cc[VMIN] = 1;
	data->termios_select.c_cc[VTIME] = 0;
	data->termios_select.c_iflag &= ~(INLCR);
	tcsetattr(STDOUT_FILENO, TCSAFLUSH, &(data->termios_select));
	tputs(data->termcaps.ti, 1, output);
	tputs(data->termcaps.vi, 1, output);
}

void	unset_terminal(struct s_select *data)
{
	tputs(data->termcaps.vs, 1, output);
	tputs(data->termcaps.te, 1, output);
	close(data->fd);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &(data->termios_backup));
}
