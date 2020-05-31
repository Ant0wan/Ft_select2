/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchline.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 10:20:12 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/31 10:32:39 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHLINE_H
# define SEARCHLINE_H

# include "select.h"

# define READLINE_DEFAULT_BUFFER_SIZE 256

void	insert_text(const char *string, int len);
void	clear_line(void);
void	init_line_buffer(void);
void	update_line(void);

#endif
