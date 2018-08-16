/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:15:28 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/16 16:30:39 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfile.h"

static	void	sort_set(int *set, int len)
{
	int i;

	i = -1;
	while (++i < len)
	{
		if (set[i] > set[1 + i])
		{
			set[i] += set[1 + i];
			set[1 + i] = set[i] - set[1 + i];
			set[i] -= set[1 + i];
			i = -1;
		}
	}
}

static	int		put_to_stack(t_lst *stack, int *set, int len)
{
	int i;

	i = -1;
	while (++i < len)
		if (set[i] == set[1 + i])
			return (1);
	while (stack)
	{
		i = -1;
		while (++i < len)
		{
			if (set[i] == stack->stack)
				stack->pos = i;
		}
		stack = stack->next;
	}
	return (0);
}

int				set_order(t_lst *stack)
{
	int		len;
	int		*order;
	t_lst	*run;

	run = stack;
	len = 0;
	while (run && ++len)
		run = run->next;
	order = (int *)malloc(sizeof(int) * len);
	run = stack;
	len = 0;
	while (run)
	{
		order[len++] = run->stack;
		run = run->next;
	}
	sort_set(order, -1 + len);
	if (put_to_stack(stack, order, len))
	{
		free(order);
		return (1);
	}
	free(order);
	return (0);
}
