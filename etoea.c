/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etoea.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:43:50 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/20 11:04:40 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	see_order(t_lst *stack, int *set)
{
	set[0] = 0;
	set[1] = 0;
	set[2] = 0;
	if (stack && stack->next)
	{
		set[0] = stack->pos;
		stack = stack->next;
		set[1] = stack->pos;
		while (stack->next)
			stack = stack->next;
		set[2] = stack->pos;
	}
}

int		order(t_lst *stack)
{
	int i;

	i = 0;
	while (stack->next)
	{
		i = stack->stack;
		stack = stack->next;
		if (i > stack->stack)
			return (1);
	}
	return (0);
}

char	*end_to_end_stack_a(t_lst *stack, char *line)
{
	int	set[3];

	see_order(stack, set);
	if (order(stack) && set[0] < set[1] && set[0] < set[2])
		return (ft_strcpy(line, "pb"));
	if (set[0] < set[1] && set[0] > set[2])
		return (ft_strcpy(line, "rra"));
	if (set[0] > set[2])
		return (ft_strcpy(line, "ra"));
	if (set[0] > set[1])
		return (ft_strcpy(line, "sa"));
	return (line);
}
