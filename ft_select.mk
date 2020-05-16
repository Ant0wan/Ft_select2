# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_select.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/16 14:31:51 by abarthel          #+#    #+#              #
#    Updated: 2020/05/16 19:04:32 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SOURCES_PATH := ./

SOURCES := \
		color.c \
		data.c \
		display.c \
		elements.c \
		keymap.c \
		main.c \
		sig.c \
		terminal.c \
		trim.c

OBJECTS := $(patsubst %.c,%.o,$(addprefix $(SOURCES_PATH), $(SOURCES)))

PATH_LIB := ./42Libc/

INCLUDES := -I$(PATH_LIB)include/

DEPENDS := $(patsubst %.c,%.d,$(addprefix $(SOURCES_PATH), $(SOURCES)))

LDLIBS += $(PATH_LIB)libft.a -ltermcap

LDFLAGS += $(DEBUG)

CFLAGS += -Wall -Wextra -Werror -g3 $(DEBUG) #-D_POSIX_C_SOURCE
#CFLAGS += -fno-builtin -O2

DEBUG += -fsanitize=address
