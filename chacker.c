/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chacker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:21:32 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/09 11:14:18 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfile.h"

int		main(int argi, char **args)
{
	t_lst	*stack_a;
	t_lst	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (varify(args, argi))
		return (0);
	(argi == 2 ? (stack_a = single_str(args[1]))\
		: (stack_a = multi_args(args, argi)));
	play_moves(&stack_a, &stack_b);
	check(stack_a, stack_b, 0);
	free(stack_a);
	free(stack_b);
	return (0);
}
