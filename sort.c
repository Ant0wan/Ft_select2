/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 21:36:05 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/19 14:07:22 by abarthel         ###   ########.fr       */
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
void	sort(struct s_select *data)
{
	
}


int	alpha_compare(struct s_select *data)
{
	size_t	len1;
	size_t	len2;
	int		ret_time_cmp;
	_Bool	low_equal;

	len1 = ft_strlen(arg->ret_readdir->d_name);
	len2 = ft_strlen(arg->voyager->d_name);
	low_equal = ft_strcasecmp(arg->ret_readdir->d_name, arg->voyager->d_name) ? 0 : 1;
	if (low_equal)
	{
		if (len1 != len2)
			return (len1 > len2);
		else
			return (ft_strcmp(arg->ret_readdir->d_name, arg->voyager->d_name));
	}
	else
		return (ft_strcasecmp(arg->ret_readdir->d_name, arg->voyager->d_name));
}*/
