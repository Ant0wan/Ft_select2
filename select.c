/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:48:35 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 13:07:56 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	set_select_mode(struct s_select *data, union u_buffer input)
{
	(void)input;
	data->mode = SELECT;
	data->search_error = 0;
	bar(data);
}

void	quit(struct s_select *data, union u_buffer input)
{
	(void)data;
	(void)input;
	end_pgm(-128);
}
