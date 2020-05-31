/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_occur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 18:44:59 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 18:49:59 by abarthel         ###   ########.fr       */
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
			// Select the element and pose cursor selection on it
			return ;
		}
		e = e->next;
	}
	data->search_error = 1;
	tputs(data->termcaps.vi, 1, output);
	bar(data);
	sleep(1);
}
