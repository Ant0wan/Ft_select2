/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchline.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 10:20:12 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 10:53:52 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHLINE_H
# define SEARCHLINE_H

# include "../select.h"

# define READLINE_DEFAULT_BUFFER_SIZE 256

void	insert_text(struct s_select *data, const char *string, int len);
void	init_line_buffer(struct s_select *data);
void	update_line(struct s_select *data);

#endif
