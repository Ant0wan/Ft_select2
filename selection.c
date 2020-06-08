/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 13:16:44 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/08 13:23:14 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	display_selection(struct s_select *data)
{
	int	has_prev;

	has_prev = 0;
	while (data->elements)
	{
		if (!has_prev && data->elements->selected)
		{
			has_prev = 1;
			ft_printf("%s", data->elements->arg);
		}
		else if (has_prev && data->elements->selected)
			ft_printf(" %s", data->elements->arg);
		data->elements = data->elements->next;
	}
}
