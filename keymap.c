/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:59:02 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/16 12:55:17 by abarthel         ###   ########.fr       */
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

/*
** Insertion mode
*/

char	*g_insert_std_keymap[] =
{
	[ 0 ... 128 ] = { NULL }
};

char	*g_insert_ctlx_keymap[] =
{
	[ 0 ... 128 ] = { NULL }
};

char	*g_insert_meta_keymap[] =
{
	[ 0 ... 128 ] = { NULL }
};

/*
** Command mode
*/

char	*g_cmd_std_keymap[] =
{
	[ 0 ... 128 ] = { NULL }
};

char	*g_cmd_ctlx_keymap[] =
{
	[ 0 ... 128 ] = { NULL }
};

char	*g_cmd_meta_keymap[] =
{
	[ 0 ... 128 ] = { NULL }
};
