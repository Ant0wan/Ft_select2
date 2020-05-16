/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 17:16:26 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/16 18:42:02 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static char	*other_color(struct stat *st)
{
	if (S_ISDIR(st->st_mode))
	{
		if ((st->st_mode & S_IWOTH) != 0)
			return (OTHER_WRITABLE);
		else if ((st->st_mode & S_ISVTX) != 0)
			return (STICKY);
		return (DIRECTORY);
	}
	else if (S_ISLNK(st->st_mode))
		return (SYMLINK);
	else if (S_ISFIFO(st->st_mode))
		return (PIPE);
	else if (S_ISSOCK(st->st_mode))
		return (SOCKET);
	else if (S_ISBLK(st->st_mode))
		return (BLOCK_DEVICE);
	else if (S_ISCHR(st->st_mode))
		return (CHAR_DEVICE);
	return (DEFAULT);
}

char		*get_color(struct stat *st)
{
	if (S_ISREG(st->st_mode))
	{
		if ((st->st_mode & S_ISUID) != 0)
			return (SETUID);
		else if ((st->st_mode & S_ISGID) != 0)
			return (SETGID);
		else if ((st->st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)) != 0)
			return (EXECUTABLE);
		else if (1 < st->st_nlink)
			return (SYMLINK);
		return (DEFAULT);
	}
	return (other_color(st));
}
