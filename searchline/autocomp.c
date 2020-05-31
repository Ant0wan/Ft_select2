/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 17:26:23 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 18:02:48 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchline.h"

char	*suggestion(struct s_select *data)
{
	struct s_element	*e;

	e = data->elements;
	while (e)
	{
		if (!ft_strncmp(e->arg, data->search_line, data->sl_len))
			return (&(e->arg[data->sl_cpos]));
		e = e->next;
	}
	return (NULL);
}

void	disp_sug(struct s_select *data)
{
	char	*s;

	s = suggestion(data);
	if (s)
	{
		ft_dprintf(data->fd, "%s%s%s", GRMODE, s, DEFAULT);
		tputs(tgoto(data->termcaps.cm, data->sl_cpos + 1, data->win.ws_row), 1, output);
	}
}
