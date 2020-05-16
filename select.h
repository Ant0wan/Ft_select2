/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 19:04:22 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/16 14:20:47 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

struct	s_termcaps
{
	char	*cd;
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

struct	s_tc_string
{
	const char *const	var;
	char				**value;
	int				available;
};

struct	s_select
{
	char			*ttyname; // No free
	struct s_tc_string	tc_string[11]; // No free
	struct termios		termios_backup; // No free
	struct s_termcaps	termcaps; // No free
};

union					u_buffer
{
	unsigned long	value;
	char			buf[sizeof(unsigned long)];
};

union u_buffer			read_key(void);

#endif
