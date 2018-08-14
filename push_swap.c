/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 10:21:11 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/14 17:27:03 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include <stdio.h>

void	play_algo(t_lst **stack_a, t_lst **stack_b)
{
	char *line;

	line = ft_strnew(3);
	while (!check(*stack_a, *stack_b, 1))
	{
		ft_bzero(line, 3);
		line = end_to_end(stack_a, stack_b, line);
		if (!line[0])
			return ;
		ft_putstr(line);
		ft_putchar('\n');
		make_a_move(stack_a, stack_b, line);

	}
}

int main(int argi, char **args)
{
	t_lst	*stack_a;
	t_lst	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	//		ft_putstr("cc");
	if (varify(args, argi))
		return (0);
	//		ft_putstr("gg");
	(argi == 2 ? (stack_a = single_str(args[1]))\
		: (stack_a = multi_args(args, argi)));
	play_algo(&stack_a, &stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
