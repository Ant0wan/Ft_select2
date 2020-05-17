/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 11:23:23 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/17 11:27:47 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	output(int c)
{
	if (write(STDOUT_FILENO, &c, sizeof(c)) != -1)
		return ((unsigned char)c);
	else
		return (EOF);
}
