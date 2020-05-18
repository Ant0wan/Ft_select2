/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:48:00 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/18 14:48:14 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	set_search_mode(struct s_select *data, union u_buffer input)
{
	(void)input;
	data->mode = SEARCH;
	bar(data);
}
