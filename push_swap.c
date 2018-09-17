/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 10:21:11 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/20 11:33:16 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include <stdio.h>

void	free_stack(t_lst **stack)
{
	t_lst *del_temp;

	if (!(*stack))
		return ;
	del_temp = (*stack);
	(*stack) = (*stack)->next;
	if ((*stack))
		free_stack(stack);
	free(del_temp);
}

void	play_algo(t_lst **stack_a, t_lst **stack_b)
{
	char	*line;
	int		i;

	i = 0;
	line = ft_strnew(3);
	while (!check(*stack_a, *stack_b, 1))
	{
		ft_bzero(line, 4);
		line = end_to_end_stack_a(*stack_a, line);
		line = end_to_end_stack_b(stack_a, stack_b, line, &i);
		ft_putendl(line);
		make_a_move(stack_a, stack_b, line);
		i++;
	}
	free(line);
}

int		main(int argi, char **args)
{
	int		state;
	t_lst	*stack_a;
	t_lst	*stack_b;

	state = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (varify(args, argi))
		return (0);
	(argi == 2 ? (stack_a = single_str(args[1], &state))\
		: (stack_a = multi_args(args, argi, &state)));
	if (state || set_order(stack_a))
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (error_return());
	}
	play_algo(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
