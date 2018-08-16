# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 13:45:26 by kmaputla          #+#    #+#              #
#    Updated: 2018/08/16 17:57:29 by kmaputla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

lib = ./libft/libft.a
PSH = push_swap.c
CHK = checker.c
SRC =	etoea.c\
		etoeb.c\
		get_list.c\
		get_move.c\
		make_moves.c\
		repeat_num.c\

all:
	gcc -Wall -Werror -Wextra -o push_swap $(PSH) $(SRC) $(lib)
	gcc -Wall -Werror -Wextra -o checker  $(CHK) $(SRC) $(lib)

.PHONY : fclean  clean f re norm

libft:
	make -C libft/

fclean:clean
	make fclean -C libft/
	rm $(lib)
	rm checker
	rm push_swap

clean:
	make clean -C libft/

f:all clean

re:fclean all

norm:
	norminette $(PUSH)
	norminette $(CHECK)
	norminette $(SRC)
	norminette ft_to*.c
	norminette libft.h
