/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 11:23:23 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/17 11:52:55 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int	output(int c)
{
	struct s_select	*data;

	data_static_method(NULL, &data);
	if (write(data->fd, &c, sizeof(c)) != -1)
		return ((unsigned char)c);
	else
		return (EOF);
}
