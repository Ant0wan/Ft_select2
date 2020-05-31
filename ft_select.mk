# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_select.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/16 14:31:51 by abarthel          #+#    #+#              #
#    Updated: 2020/05/31 10:30:04 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SOURCES_PATH := ./

SOURCES := \
		bar.c \
		color.c \
		command.c \
		data.c \
		display.c \
		elements.c \
		frame.c \
		keymap.c \
		main.c \
		output.c \
		search.c \
		select.c \
		sig.c \
		sort.c \
		terminal.c \
		utils_suite.c \
		utils_suite2.c \
		searchline/display.c \
		searchline/emacs_keymap.c \
		searchline/searchline.c \
		searchline/text2.c \
		searchline/text3.c \
		searchline/text4.c \
		searchline/text5.c \
		searchline/text7.c \
		searchline/text8.c \
		searchline/text.c \
		searchline/text_hist.c \
		searchline/utils_suite2.c \
		searchline/utils_suite.c

OBJECTS := $(patsubst %.c,%.o,$(addprefix $(SOURCES_PATH), $(SOURCES)))

PATH_LIB := ./42Libc/

INCLUDES := -I$(PATH_LIB)include/

DEPENDS := $(patsubst %.c,%.d,$(addprefix $(SOURCES_PATH), $(SOURCES)))

LDLIBS += -ltermcap $(PATH_LIB)libft.a

LDFLAGS += $(DEBUG)

CFLAGS += -Wall -Wextra -Werror -g3 $(DEBUG) #-D_POSIX_C_SOURCE
#CFLAGS += -fno-builtin -O2

DEBUG += -fsanitize=address
