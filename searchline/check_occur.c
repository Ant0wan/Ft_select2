/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_occur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 18:44:59 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/08 13:13:21 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchline.h"

void	check_occur(struct s_select *data)
{
	struct s_element	*e;

	e = data->elements;
	while (e)
	{
		if (!ft_strcmp(e->arg, data->search_line))
		{
			data->cursor = e;
			display_elements(data);
			break ;
		}
		e = e->next;
	}
	tputs(data->termcaps.vi, 1, output);
	if (!e)
	{
		data->search_error = 1;
		bar(data);
		sleep(1);
	}
}
