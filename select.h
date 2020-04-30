/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 19:04:22 by abarthel          #+#    #+#             */
/*   Updated: 2020/04/30 19:07:13 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

union					u_buffer
{
	unsigned long	value;
	char			buf[sizeof(unsigned long)];
};

union u_buffer			read_key(void);

#endif
