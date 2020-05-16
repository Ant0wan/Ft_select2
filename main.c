/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 13:07:38 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/16 14:29:11 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Commands:
** /name :search by name
** :s time, size, chmod, name, date
** :help : display help message
** else display error msg if needed
*/

/*
** 1. Check terminal capabilities: should work with dumb mode
** 2. Check argc > 1 : if no arg, then error then return
** 3. Set signals
** 4. Check valid argv and remove duplicates: check inode
** 5. Display files alnum sorted files
** 6. Unset terminal
** 7. Unset signals
** 8. Return values
*/

#include "select.h"

int main(int argc, char **argv)
{
	struct s_select	*data;
	(void)argc;
	(void)argv;

	data = ft_memalloc(sizeof(struct s_select));
	if (!data)
		return (EXIT_FAILURE);
	set_terminal(data);
	unset_terminal(data);
	return (EXIT_SUCCESS);
}
