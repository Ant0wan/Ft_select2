# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/16 14:31:43 by abarthel          #+#    #+#              #
#    Updated: 2020/05/16 14:58:34 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include ft_select.mk

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(PATH_LIB)/libft.a $(OBJECTS)
	@$(CC) $^ -o $@ $(LDLIBS) $(LDFLAGS)
	@printf "\n\e[38;5;44m%4s [\e[1m$(NAME) built]\n\n\e[0m"

libft/libft.a: dep
	@$(MAKE) lib -j -C $(PATH_LIB)

dep:

clean:
	@$(RM) $(OBJECTS) $(DEPENDS)
	@$(MAKE) clean -C $(PATH_LIB)

fclean:
	@$(RM) $(OBJECTS) $(DEPENDS) $(NAME)
	@$(MAKE) fclean -C $(PATH_LIB)

re: fclean $(NAME)

test: all
	@$(TEST)

-include $(DEPENDS)

%.o: %.c Makefile $(NAME).mk
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@
	@printf "\e[38;5;155m%-24s \e[38;5;37mobject built\n\e[0m" $(notdir $(basename $@))
