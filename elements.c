/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 17:04:25 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/08 16:50:10 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	del_one(struct s_element *element)
{
	struct s_element	*ep;
	struct s_element	*en;

	ep = element->previous;
	en = element->next;
	if (ep)
		ep->next = en;
	if (en)
		en->previous = ep;
	free(element);
}

void	free_elements(struct s_element *element)
{
	if (element)
	{
		free_elements(element->next);
		free(element);
	}
}

static struct s_element	*node_element(struct s_element *prev, char *av)
{
	struct s_element	*node;

	node = ft_memalloc(sizeof(struct s_element));
	if (!node)
		end_pgm(-126);
	node->previous = prev;
	node->arg = av;
	node->len = ft_strlen(av);
	stat(av, &(node->st));
	node->color = get_color(&(node->st));
	return (node);
}

static void	add_to_elements(struct s_select *data, char *av)
{
	static struct s_element	*last;

	if (!data->elements)
	{
		data->elements = node_element(NULL, av);
		last = data->elements;
	}
	else
	{
		last->next = node_element(last, av);
		last = last->next;
	}
}

void	fill_elements(struct s_select *data, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		add_to_elements(data, argv[i]);
		++i;
	}
}
