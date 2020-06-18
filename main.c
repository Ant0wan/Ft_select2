/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 13:07:38 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/18 23:47:50 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

#define NEED_ARG "ft_select requires at least one argument.\n\nUsage:\t./ft_select ARG...\n"

static void	ft_select(struct s_select *data)
{
	int	acting;

	data->cursor = data->elements;
	acting = 0;
	while (!acting)
	{
		if (!data->no_refresh)
			display(data);
		data->no_refresh = 0;
		acting = actions(data);
	}
}

int		main(int argc, char **argv)
{
	struct s_select	*data;

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
		sort(data);
		ft_select(data);
		unset_terminal(data);
		display_selection(data);
		free_data(&data);
	}
	else
	{
		write(STDERR_FILENO, NEED_ARG, ft_strlen(NEED_ARG));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
