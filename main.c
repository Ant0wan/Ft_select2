/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 13:07:38 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/08 18:58:00 by abarthel         ###   ########.fr       */
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
** 2. Check argc > 1 : if no arg, then error then return
** 1. Check terminal capabilities: should work with dumb mode
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
	int		acting;

	acting = 0;
	if (argc > 1)
	{
		data = ft_memalloc(sizeof(struct s_select));
		if (!data)
			return (EXIT_FAILURE);
		data_static_method(data, NULL);
		init_keymaps(data);
		init_sort_list(data);
		set_terminal(data);
		set_signals();
		fill_elements(data, argc, argv);
		data->cursor = data->elements;
		sort(data);

		while (!acting)
		{
			if (!data->no_refresh)
				display(data); // if acting was none, no need to display
			data->no_refresh = 0;
			acting = actions(data);
		}

		unset_terminal(data);
		display_selection(data);
		free_data(&data); // Free function of data
	}
	else
	{
		write(STDERR_FILENO, NEED_ARG, ft_strlen(NEED_ARG));
		return (1);
	}
	return (EXIT_SUCCESS);
}
