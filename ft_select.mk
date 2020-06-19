# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_select.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/16 14:31:51 by abarthel          #+#    #+#              #
#    Updated: 2020/06/19 16:44:27 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SOURCES_PATH := ./

SOURCES := \
		actions.c \
		bar.c \
		color.c \
		command.c \
		compare.c \
		data.c \
		display.c \
		elements.c \
		frame.c \
		ft_merge_sort.c \
		io.c \
		keymap.c \
		main.c \
		page.c \
		search.c \
		select.c \
		selection.c \
		sig.c \
		sort.c \
		terminal.c \
		utils_suite.c \
		utils_ctrl.c \
		searchline/autocomp.c \
		searchline/check_occur.c \
		searchline/search_keymap.c \
		searchline/searchline.c \
		searchline/text.c \
		searchline/text2.c \
		searchline/text3.c \
		searchline/text4.c \
		searchline/text5.c

OBJECTS := $(patsubst %.c,%.o,$(addprefix $(SOURCES_PATH), $(SOURCES)))

PATH_LIB := ./42Libc/

INCLUDES := -I$(PATH_LIB)include/ -I./searchline/

DEPENDS := $(patsubst %.c,%.d,$(addprefix $(SOURCES_PATH), $(SOURCES)))

LDLIBS += -ltermcap $(PATH_LIB)libft.a

CFLAGS += -Wall -Wextra -Werror -g3
