/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 19:04:22 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/16 15:26:58 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

# include <curses.h>
# include <signal.h>
# include <stdio.h>
# include <term.h>
# include <unistd.h>

# include "libft.h"

# define NB_TERMS 11

struct	s_termcaps
{
	char	*cd; // wipe
	char	*ce; // clear end of line
	char	*vs; // cursor visible
	char	*vi; // cursor not visible
	char	*us; // underline
	char	*af; // font color
	char	*ab; // background color
	char	*cm; // move position
	char	*me; // reset colors
	char	*ti; // Enable full screen
	char	*te; // Disable full screen
};

union	u_termcaps
{
	char			*index[sizeof(struct s_termcaps)];
	struct s_termcaps	value;
};

struct	s_select
{
	char			*ttyname; // No free
	char			*tc_string[NB_TERMS]; // No free
	struct termios		termios_backup; // No free
	struct termios		termios_select; // No free
	union u_termcaps	termcaps; // No free
};

union					u_buffer
{
	unsigned long	value;
	char			buf[sizeof(unsigned long)];
};

union u_buffer			read_key(void);

int	set_terminal(struct s_select *data);
int	unset_terminal(struct s_select *data);

#endif
