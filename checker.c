/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chacker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:21:32 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/20 11:38:29 by kmaputla         ###   ########.fr       */
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

int		clean_up(t_lst **stack_a, t_lst **stack_b, int state)
{
	free_stack(stack_a);
	free_stack(stack_b);
	if (state)
		error_return();
	return (0);
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
		return (0);
	}
	if (varify(args, argi))
		return (0);
	(argi == 2 ? (stack_a = single_str(args[1], &state))\
		: (stack_a = multi_args(args, argi, &state)));
	if (state || set_order(stack_a))
		return (clean_up(&stack_a, &stack_b, 1));
	if (play_moves(&stack_a, &stack_b))
		return (clean_up(&stack_a, &stack_b, 1));
	check(stack_a, stack_b, 0);
	return (clean_up(&stack_a, &stack_b, 0));
}
