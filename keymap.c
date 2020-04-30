/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:59:02 by abarthel          #+#    #+#             */
/*   Updated: 2020/04/30 19:06:37 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

union u_buffer	read_key(void)
{
	union u_buffer	buffer_u;

	buffer_u.value = 0;
	read(STDIN_FILENO, buffer_u.buf, sizeof(buffer_u.buf));
	return (buffer_u);
}

char	*g_standard_keymap[] =
{
	[ 0 ... 128 ] = { NULL }
};

char	*g_ctlx_keymap[] =
{
	[ 0 ... 128 ] = { NULL }
};

char	*g_meta_keymap[] =
{
	[ 0 ... 128 ] = { NULL }
};
