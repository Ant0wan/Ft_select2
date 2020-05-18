/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 21:36:05 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/18 21:47:42 by abarthel         ###   ########.fr       */
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
