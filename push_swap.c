/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 10:21:11 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/09 13:50:09 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfile.h"

void	play_algo(t_lst **stack_a, t_lst **stack_b)
{
	int		i;
	t_lst	*temp_end_stack;
	t_lst	*temp_start_stack;

	i = 0;
	while (!check(*stack_a, *stack_b, 1))
	{
		i = (*stack_a)->stack;
		temp_start_stack = (*stack_a)->next;
		temp_end_stack = (*stack_a);
		while (temp_end_stack->next)
			temp_end_stack = temp_end_stack->next;
		if (temp_end_stack->stack < i)
		{
			ft_putstr("ra");
			make_a_move(stack_a, stack_b, "ra");
		}
		else if (i > temp_start_stack->stack)
		{
			ft_putstr("sa");
			make_a_move(stack_a, stack_b, "sa");
		}
		else if (i < temp_start_stack->stack)
		{
			ft_putstr("rra");
			make_a_move(stack_a, stack_b, "rra");
		}
		else
		{
			ft_putstr("ra");
			make_a_move(stack_a, stack_b, "ra");
		}

	}
}

int main(int argi, char **args)
{
	t_lst	*stack_a;
	t_lst	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
			ft_putstr("cc");
	if (varify(args, argi))
		return (0);
			ft_putstr("gg");
	(argi == 2 ? (stack_a = single_str(args[1]))\
		: (stack_a = multi_args(args, argi)));
	play_algo(&stack_a, &stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
