/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 13:17:43 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/16 14:56:59 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static void	set_tercamps(struct s_select *data)
{
	(void)data;
	/*                    termcap,   pointeur,    availability            */
//	data->tc_string[0] = {"cd", &(data->termcaps.cd), 1}; // wipe
//	data->tc_string[1] = {"ce", &(data->termcaps.ce), 1}; // clear end of line
//	data->tc_string[2] = {"vs", &(data->termcaps.vs), 1}; // cursor visible
//	data->tc_string[3] = {"vi", &(data->termcaps.vi), 1}; // cursor not visible
//	data->tc_string[4] = {"us", &(data->termcaps.us), 1}; // underline
//	data->tc_string[5] = {"AF", &(data->termcaps.af), 1}; // font color
//	data->tc_string[6] = {"AB", &(data->termcaps.ab), 1}; // background color
//	data->tc_string[7] = {"cm", &(data->termcaps.cm), 1}; // move position
//	data->tc_string[8] = {"me", &(data->termcaps.me), 1}; // reset colors
}

int	set_terminal(struct s_select *data)
{
	// Check if tty
	if (isatty(STDOUT_FILENO))
	{
		data->ttyname = ttyname(STDOUT_FILENO);
		if (data->ttyname == NULL)
			data->ttyname = "dumb";
	}
	// Check and get termcaps from tty name
	set_tercamps(data);

	// Set term
	data->termios_select.c_lflag &= ~(ICANON | ECHO);
	tputs(data->termcaps.ti, 1, putchar); // Full screen
	tputs(data->termcaps.vi, 1, putchar); // Make cursor invisible
	return (0);
}

int	unset_terminal(struct s_select *data)
{
	data->termios_select.c_lflag |= (ICANON | ECHO);
	tputs(data->termcaps.te, 1, putchar); // Disable full screen
	tputs(data->termcaps.vs, 1, putchar); // Make cursor visible
	return (0);
}
