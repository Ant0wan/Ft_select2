/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 17:26:23 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 18:13:02 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchline.h"

void	suggestion(struct s_select *data)
{
	struct s_element	*e;

	data->suggestion = NULL;
	e = data->elements;
	while (e)
	{
		if (!ft_strncmp(e->arg, data->search_line, data->sl_len))
		{
			data->suggestion = e;
			return ;
		}
		e = e->next;
	}
}

void	disp_sug(struct s_select *data)
{
	suggestion(data);
	if (data->suggestion)
	{
		ft_dprintf(data->fd, "%s%s%s", GRMODE, &(data->suggestion->arg[data->sl_cpos]), DEFAULT);
		tputs(tgoto(data->termcaps.cm, data->sl_cpos + 1, data->win.ws_row), 1, output);
	}
}
