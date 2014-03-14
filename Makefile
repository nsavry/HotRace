# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/14 05:48:46 by nsavry            #+#    #+#              #
#    Updated: 2013/12/14 14:37:19 by nsavry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hotrace

FTC = main.c\
	  ft_current_one.c\
	  ft_current_two.c

FTO = $(subst .c,.o,$(FTC))

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(FTO)
	gcc -o $(NAME) $(FTO)

%.o: %.c
	gcc -Wall -Werror -Wextra -I./ -c $<	

clean:
	rm -rf $(FTO)

fclean: clean
	rm -rf $(NAME)

re: fclean all
