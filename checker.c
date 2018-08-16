/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chacker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:21:32 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/16 17:11:23 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfile.h"

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

int		main(int argi, char **args)
{
	int		state;
	t_lst	*stack_a;
	t_lst	*stack_b;

	state = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argi < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (varify(args, argi))
		return (0);
	(argi == 2 ? (stack_a = single_str(args[1], &state))\
		: (stack_a = multi_args(args, argi, &state)));
	if (state || set_order(stack_a))
		return (error_return());
	if (play_moves(&stack_a, &stack_b))
		return (error_return());
	check(stack_a, stack_b, 0);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
