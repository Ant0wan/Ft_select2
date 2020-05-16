/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 13:00:32 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/16 14:41:16 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static void	end_pgm(int sig)
{
	(void)sig;
}

static void	suspend(int sig)
{
	(void)sig;
}

static void	wins_resize_sighandler(int sig)
{
	(void)sig;
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
	signal(SIGCONT, wins_resize_sighandler);
	signal(SIGWINCH, wins_resize_sighandler);
}
