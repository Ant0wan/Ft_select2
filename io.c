/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 11:23:23 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/23 14:44:08 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "searchline.h"

int				output(int c)
{
	struct s_select	*data;

	data_static_method(NULL, &data);
//	if (write(data->fd, &c, sizeof(c)) != -1)
	if (write(data->fd, &c, 1) != -1)
		return ((unsigned char)c);
	else
		return (EOF);
}

union u_buffer	read_key(void)
{
	union u_buffer	buffer_u;
	int				ret;

	buffer_u.value = 0;
	ret = read(STDIN_FILENO, buffer_u.buf, sizeof(buffer_u.buf));
	if (ret == -1)
		buffer_u.value = -1;
	return (buffer_u);
}
