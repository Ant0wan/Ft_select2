/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:43:00 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/18 14:45:12 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	set_command_mode(struct s_select *data, union u_buffer input)
{
	(void)input;
	data->mode = COMMAN;
	bar(data);
}
