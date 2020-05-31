/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_occur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 18:44:59 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 18:46:39 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchline.h"

void	check_occur(struct s_select *data)
{
	data->search_error = 1;
	tputs(data->termcaps.vi, 1, output);
	bar(data);
	sleep(1);
}
