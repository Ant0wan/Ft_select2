/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 13:17:43 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/16 14:22:04 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static void	set_tercamps(struct s_select *data)
{
	data->tc_strings[0] = {"cd", &(data->termcaps.cd), 1}; // wipe
	data->tc_strings[1] = {"ce", &(data->termcaps.ce), 1}; // clear end of line
	data->tc_strings[2] = {"vs", &(data->termcaps.vs), 1}; // cursor visible
	data->tc_strings[3] = {"vi", &(data->termcaps.vi), 1}; // cursor not visible
	data->tc_strings[4] = {"us", &(data->termcaps.us), 1}; // underline
	data->tc_strings[5] = {"AF", &(data->termcaps.af), 1}; // font color
	data->tc_strings[6] = {"AB", &(data->termcaps.ab), 1}; // background color
	data->tc_strings[7] = {"cm", &(data->termcaps.cm), 1}; // move position
	data->tc_strings[8] = {"me", &(data->termcaps.me), 1}; // reset colors
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
	termios_p.c_lflag &= ~(ICANON | ECHO);
	tputs(termcaps.ti, 1, tc_output); // Full screen
	tputs(termcaps.vi, 1, tc_output); // Make cursor invisible
}

int	unset_terminal(void)
{
	termios_p.c_lflag |= (ICANON | ECHO);
	tputs(termcaps.te, 1, tc_output); // Disable full screen
	tputs(termcaps.vs, 1, tc_output); // Make cursor visible
}
