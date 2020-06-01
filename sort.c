/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 21:36:05 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/01 17:14:38 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	init_sort_list(struct s_select *data)
{
	static struct s_sort	alpha;
	static struct s_sort	size;
	static struct s_sort	time;
	static struct s_sort	type;
	static struct s_sort	uid;

	alpha.prev = NULL;
	alpha.next = &size;
	size.prev = &alpha;
	size.next = &time;
	time.prev = &size;
	time.next = &type;
	type.prev = &time;
	type.next = &uid;
	uid.prev = &type;
	uid.next = NULL;
	alpha.name = "alphabetical";
	size.name = "    size    ";
	time.name = "    time    ";
	type.name = "    type    ";
	uid.name = "    uid     ";
	data->sort = &alpha;
}

void	right_sort_mode(struct s_select *data, union u_buffer input)
{
	(void)input;
	if (data->sort->next)
	{
		data->sort = data->sort->next;
		bar(data);
	}
}

void	left_sort_mode(struct s_select *data, union u_buffer input)
{
	(void)input;
	if (data->sort->prev)
	{
		data->sort = data->sort->prev;
		bar(data);
	}
}

/*
** Linux like alpha num sort
*/

int	alpha_compare(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	int	ret_cmp;
	_Bool	low_equal;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ret_cmp = ft_strcasecmp(s1, s2);
	low_equal = ret_cmp ? 0 : 1;
	if (low_equal)
	{
		if (len1 != len2)
			return (len1 > len2);
		else
			return (ft_strcmp(s1, s2));
	}
	else
		return (ret_cmp);
}

void	fcompare(struct s_select *data, struct s_element **e1, struct s_element **e2, struct s_element **h)
{
	(void)data;
	if (alpha_compare((*e1)->arg, (*e2)->arg) > 0) // Not always strcmp, function pointer depending on data->sort
	{
		*h = *e2;
		*e2 = (*e2)->next;
	}
	else
	{
		*h = *e1;
		*e1 = (*e1)->next;
	}
}

void	sort(struct s_select *data)
{
	ft_merge_sort(&data->elements, data);
}
