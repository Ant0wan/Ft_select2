/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 17:37:42 by abarthel          #+#    #+#             */
/*   Updated: 2020/06/01 17:42:07 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

/*
** Linux like alpha num sort
*/

int	alpha_compare(struct s_element *e1, struct s_element *e2)
{
	size_t	len1;
	size_t	len2;
	int	ret_cmp;
	_Bool	low_equal;

	len1 = ft_strlen(e1->arg);
	len2 = ft_strlen(e2->arg);
	ret_cmp = ft_strcasecmp(e1->arg, e2->arg);
	low_equal = ret_cmp ? 0 : 1;
	if (low_equal)
	{
		if (len1 != len2)
			return (len1 > len2);
		else
			return (ft_strcmp(e1->arg, e2->arg));
	}
	else
		return (ret_cmp);
}

int	size_compare(struct s_element *e1, struct s_element *e2)
{
	return (e1->st.st_size > e2->st.st_size);
}

int	time_compare(struct s_element *e1, struct s_element *e2)
{
	return (e1->st.st_mtime > e2->st.st_mtime);
}

int	type_compare(struct s_element *e1, struct s_element *e2)
{
	return (e1->st.st_mode > e2->st.st_mode);
}

int	uid_compare(struct s_element *e1, struct s_element *e2)
{
	return (e1->st.st_uid > e2->st.st_uid);
}
