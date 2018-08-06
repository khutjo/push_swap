/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chacker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:21:32 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/06 18:44:54 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfile.h"
#include <stdio.h>

void	print_list(t_lst *stack_a, t_lst *stack_b)
{
	while (stack_a || stack_b)
	{
		if (stack_a && stack_b)
		{
			printf("===stack_a %d <> stack_b %d ===\n", stack_a->stack, stack_b->stack);
			stack_a = stack_a->next;
			stack_b = stack_b->next;
		}
		else if (stack_a && !stack_b)
		{
			printf("==stack_a %d <> stack_b - ===\n", stack_a->stack);
				stack_a = stack_a->next;
		}
		else if (!stack_a && stack_b)
		{
			printf("==stack_a - <> stack_b %d ===\n", stack_b->stack);
				stack_b = stack_b->next;
		}
	}
	printf("\n");
}	

int main(int argi, char **args)
{
	int		i;
	t_lst	*stack_a;
	t_lst	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argi < 2 || varify(args, argi))
	{
		ft_putstr("Error");
		return (0);
	}
	if (argi == 2)
		stack_a = single_str(args[1]);
	else
		stack_a = multi_args(args, argi);
	while (++i < 6)
		make_a_move(&stack_a, &stack_b, 10);
	print_list(stack_a, stack_b);
	make_a_move(&stack_a, &stack_b, 9);
	print_list(stack_a, stack_b);
	make_a_move(&stack_a, &stack_b, 9);
	print_list(stack_a, stack_b);
	make_a_move(&stack_a, &stack_b, 9);
	print_list(stack_a, stack_b);
	make_a_move(&stack_a, &stack_b, 9);
	print_list(stack_a, stack_b);
	make_a_move(&stack_a, &stack_b, 9);
	print_list(stack_a, stack_b);
	make_a_move(&stack_a, &stack_b, 9);
	print_list(stack_a, stack_b);
	make_a_move(&stack_a, &stack_b, 9);
	print_list(stack_a, stack_b);
	make_a_move(&stack_a, &stack_b, 9);
	print_list(stack_a, stack_b);
	make_a_move(&stack_a, &stack_b, 9);
	print_list(stack_a, stack_b);
	make_a_move(&stack_a, &stack_b, 8);
	print_list(stack_a, stack_b);
	make_a_move(&stack_a, &stack_b, 8);
	print_list(stack_a, stack_b);
	make_a_move(&stack_a, &stack_b, 8);
	print_list(stack_a, stack_b);
	make_a_move(&stack_a, &stack_b, 8);
	print_list(stack_a, stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}

