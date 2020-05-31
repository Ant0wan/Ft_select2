/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 17:46:08 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 12:47:00 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	free_data(struct s_select **data)
{
	if (*data)
	{
		free_elements((*data)->elements);
		free((*data)->search_line);
		free(*data);
		*data = NULL;
	}
}
