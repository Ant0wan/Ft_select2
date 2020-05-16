/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 13:17:43 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/16 15:28:03 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static void	set_termcaps(struct s_select *data)
{
	int	i;

	data->tc_string[0] = "cd";
	data->tc_string[1] = "ce";
	data->tc_string[2] = "vs";
	data->tc_string[3] = "vi";
	data->tc_string[4] = "us";
	data->tc_string[5] = "AF";
	data->tc_string[6] = "AB";
	data->tc_string[7] = "cm";
	data->tc_string[8] = "me";
	data->tc_string[9] = "ti";
	data->tc_string[10] = "te";
	while (i < NB_TERMS)
	{
		data->termcaps.index[i] = tgetstr(data->tc_string[i], NULL);
		++i;
	}
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
	set_termcaps(data);

	// Set term
	data->termios_select.c_lflag &= ~(ICANON | ECHO);
	tputs(data->termcaps.value.ti, 1, putchar); // Full screen
	tputs(data->termcaps.value.vi, 1, putchar); // Make cursor invisible
	return (0);
}

int	unset_terminal(struct s_select *data)
{
	data->termios_select.c_lflag |= (ICANON | ECHO);
	tputs(data->termcaps.value.te, 1, putchar); // Disable full screen
	tputs(data->termcaps.value.vs, 1, putchar); // Make cursor visible
	return (0);
}
