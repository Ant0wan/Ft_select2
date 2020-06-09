/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 17:46:08 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/09 19:03:28 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	free_data(struct s_select **data)
{
	if (*data)
	{
		exit(2);
		while ((*data)->elements->previous)
			(*data)->elements = (*data)->elements->previous;
		free_elements((*data)->elements);
		free((*data)->search_line);
		free(*data);
		*data = NULL;
	}
}
