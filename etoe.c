/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etoe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:43:50 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/14 17:25:41 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	order(t_lst **stack, int *set)
{
	t_lst	*end;

	if (!(*stack) && !(*stack)->next)
	{
		set[1] = 0;
		set[2] = 0;
		set[3] = 0;
		return (0);
	}
	set[0] = 1;
	set[1] = (*stack)->stack;
	end = (*stack)->next;
	set[2] = end->stack;
	while (end->next)
		end = end->next;
	set[3] = end->stack;
	return (1);
}
/*	if (set_a[1] < set_a[2] && set_a[1] < set_a[3])
		return (ft_strcpy(line, "pa"));
	if (set_b[0] < set_a[0] && set_a[0] < set_a[0] && set_a[0] < set_a[0])
		return (ft_strcpy(line, "pa"));
*/
char	*end_to_end_extra(int *set_a,int *set_b, char *line)
{
	if (set_a[1] > set_a[2] && set_a[1] > set_a[3] && set_a[2] < set_a[3])
		return (ft_strcpy(line, "sa"));
//	if (set_a[0] < set_a[0] && set_a[0] < set_a[0] && set_a[0] < set_a[0])
//		return (ft_strcpy(line, "sb"));
	if (set_a[1] < set_a[2] && set_a[1] > set_a[3] && set_a[2] > set_a[3])
		return (ft_strcpy(line, "ra"));
//	if (set_a[0] < set_a[0] && set_a[0] < set_a[0] && set_a[0] < set_a[0])
//		return (ft_strcpy(line, "rb"));
	if (set_a[1] > set_a[2] && set_a[1] < set_a[3] && set_a[2] < set_a[3])
		return (ft_strcpy(line, "rra"));
//	if (set_a[0] < set_a[0] && set_a[0] < set_a[0] && set_a[0] < set_a[0])
//		return (ft_strcpy(line, "rrb"));
	ft_strclr(line);
	return (line);
}
char	*end_to_end(t_lst **stack_a, t_lst **stack_b, char *line)
{
	int	set_a[4];
	int	set_b[4];

	set_a[0] = order(stack_a, set_a);
	set_b[0] = order(stack_a, set_b);
/*	if (set_a[0] && set_b[0] && set_a[1] > set_a[3] && set_a[1] < set_a[2] &&\
		   set_a[2] > set_a[3] && set_b[1] < set_b[3] && set_b[1] < set_b[2] &&\
		   set_b[2] < set_b[3])
		return (ft_strcpy(line, "rr"));
	if (set_a[0] && set_b[0] && set_a[1] < set_a[3] && set_a[1] > set_a[2] &&\
		   set_a[2] < set_a[3] && set_b[1] < set_b[3] && set_b[1] > set_b[2] &&\
		   set_b[2] < set_b[3])
		return (ft_strcpy(line, "rrr"));
	if (set_a[0] && set_b[0] && set_a[1] > set_a[2] && set_a[1] > set_a[3] &&\
		   set_a[2] > set_a[3] && set_b[1] > set_b[2] && set_b[1] > set_b[3] &&\
		   set_b[2] > set_b[3])
		return (ft_strcpy(line, "ss"));
*/	return (end_to_end_extra(set_a, set_b, line));
}
