# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_select.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/16 14:31:51 by abarthel          #+#    #+#              #
#    Updated: 2020/05/31 12:13:23 by abarthel         ###   ########.fr        #
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
		searchline/search_keymap.c \
		searchline/searchline.c \
		searchline/text.c \
		searchline/text_hist.c \
		searchline/text2.c \
		searchline/text3.c \
		searchline/text4.c \
#		searchline/text5.c \
#		searchline/text7.c \
#		searchline/text8.c 

OBJECTS := $(patsubst %.c,%.o,$(addprefix $(SOURCES_PATH), $(SOURCES)))

PATH_LIB := ./42Libc/

INCLUDES := -I$(PATH_LIB)include/ -I./searchline/

DEPENDS := $(patsubst %.c,%.d,$(addprefix $(SOURCES_PATH), $(SOURCES)))

LDLIBS += -ltermcap $(PATH_LIB)libft.a

LDFLAGS += $(DEBUG)

CFLAGS += -Wall -Wextra -Werror -g3 $(DEBUG) #-D_POSIX_C_SOURCE
#CFLAGS += -fno-builtin -O2

DEBUG += -fsanitize=address
