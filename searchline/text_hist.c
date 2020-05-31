/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_hist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 10:18:14 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 10:28:24 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchline.h"

int test_c_value(union u_buffer c)
{
	if ((ft_isprint(c.value) && c.value != 9) || c.value == 127)
		return (0);
	if (enter_rc(c))
		return (1);
	if (isctrlkey(c))
		return (1);
	if (ismetachar(c))
		return (1);
	if (isstdkey(c.value))
		return (1);
	return (0);
}

void history_up(void)
{
	char *s;

	if (g_hist->offset == g_hist->used - 1)
	{
		if (g_original_cmd)
			free(g_original_cmd);
		if (!(g_original_cmd = ft_strdup(g_line.line)))
		{
			ft_printf("./21sh: cannot allocate mmemory\n");
			return ;
		}
	}
	s = prev_hist();
	clear_line();
	if (s)
		insert_text(s, ft_strlen(s));
	else if (g_original_cmd)
		insert_text(g_original_cmd, ft_strlen(s));
}

void history_down(void)
{
	char *s;

	s = next_hist();
	clear_line();
	if (s && *s)
		insert_text(s, ft_strlen(s));
	else if (g_original_cmd)
		insert_text(g_original_cmd, ft_strlen(g_original_cmd));
}
