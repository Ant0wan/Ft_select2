/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:43:00 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/03 21:14:31 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	set_command_mode(struct s_select *data, union u_buffer input)
{
	(void)input;
	data->mode = COMMAN;
	data->no_refresh = 1;
	bar(data);
}
