/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 13:07:38 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/16 15:49:52 by abarthel         ###   ########.fr       */
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

#define NEED_ARG "ft_select requires at least one argument.\n\nUsage:\t./ft_select ARG...\n"

int main(int argc, char **argv)
{
	struct s_select	*data;
	(void)argc;
	(void)argv;

	if (argc > 1)
	{
		data = ft_memalloc(sizeof(struct s_select));
		if (!data)
			return (EXIT_FAILURE);
		set_terminal(data);
		// Loop
		unset_terminal(data);
		free(data);
	}
	else
	{
		write(STDERR_FILENO, NEED_ARG, ft_strlen(NEED_ARG));
		return (1);
	}
	return (EXIT_SUCCESS);
}
