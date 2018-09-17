# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 13:45:26 by kmaputla          #+#    #+#              #
#    Updated: 2018/08/19 13:58:26 by kmaputla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

lib = ./libft/libft.a
PUSH = push_swap
CHECK = checker
PSH = push_swap.c
CHK = checker.c
SRC =	etoea.c\
		etoeb.c\
		get_list.c\
		get_move.c\
		make_moves.c\
		repeat_num.c\

all:$(lib) $(PUSH) $(CHECK)

$(lib):
	make f -C libft/

$(PUSH):
	gcc -Wall -Werror -Wextra -o push_swap $(PSH) $(SRC) $(lib)

$(CHECK):
	gcc -Wall -Werror -Wextra -o checker  $(CHK) $(SRC) $(lib)

.PHONY : fclean  clean f re norm

fclean:clean
	make fclean -C libft/
	rm checker
	rm push_swap

clean:
	make clean -C libft/

f:fclean all clean

re:fclean all

norm:
	norminette *.h
	norminette *.c
