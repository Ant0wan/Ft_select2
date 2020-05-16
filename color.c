/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 17:16:26 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/16 17:36:33 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

#define FILE_DEFAULT	"\033[0m"
#define DIRECTORY	"\033[01;34m"
#define SYMLINK		"\033[01;36m"
#define PIPE		"\033[33m"
#define SOCKET		"\033[01;35m"
#define BLOCK_DEVICE	"\033[01;33m"
#define CHAR_DEVICE	"\033[01;33m"
#define EXECUTABLE	"\033[01;32m"
#define DOOR		"\033[01;35m"
#define SETUID		"\033[37;41m"
#define SETGID		"\033[30;43m"
#define STICKY		"\033[37;44m"
#define OTHER_WRITABLE	"\033[34;42m"
#define OW_STICKY	"\033[30;42m"
#define CA		"\033[30;41m"

char	*get_color(struct stat *st)
{
	(void)st;
	return (NULL);
}
