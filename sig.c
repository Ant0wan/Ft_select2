/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 13:00:32 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/16 16:36:02 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	data_static_method(struct s_select *set, struct s_select **get)
{
	static struct s_select	*data;

	if (set)
		data = set;
	else if (get)
		*get = data;
}

static void	end_pgm(int sig)
{
	struct s_select	*data;

	data_static_method(NULL, &data);
	tcsetattr(STDOUT_FILENO, TCSAFLUSH, &(data->termios_backup));
	/* Free data */
	exit(sig + 128);
}

static void	suspend(int sig)
{
	struct s_select	*data;

	(void)sig;
	data_static_method(NULL, &data);
	tcsetattr(STDOUT_FILENO, TCSAFLUSH, &(data->termios_backup));
}

static void	wins_resize_sighandler(int sig)
{
	(void)sig;
}

static void	cont_pgm(int sig)
{
	struct s_select	*data;

	(void)sig;
	data_static_method(NULL, &data);
	tcsetattr(STDOUT_FILENO, TCSAFLUSH, &(data->termios_select));
}

void		set_signals(void)
{
	signal(SIGALRM, end_pgm);
	signal(SIGHUP, end_pgm);
	signal(SIGINT, end_pgm);
	signal(SIGPIPE, end_pgm);
	signal(SIGQUIT, end_pgm);
	signal(SIGTERM, end_pgm);
	signal(SIGTSTP, suspend);
	signal(SIGTTIN, suspend);
	signal(SIGTTOU, suspend);
	signal(SIGCONT, cont_pgm);
	signal(SIGWINCH, wins_resize_sighandler);
}
