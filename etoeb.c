/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etoeb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 17:07:06 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/20 11:04:42 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	set_stack_b(t_lst **stack_a, t_lst **stack_b, char *prep, int *i)
{
	if (ft_strequ(prep, "sa"))
		ft_strcpy(prep, "sb");
	if (ft_strequ(prep, "ra"))
		ft_strcpy(prep, "rb");
	if (ft_strequ(prep, "rra"))
		ft_strcpy(prep, "rrb");
	ft_putendl(prep);
	i = i + 1;
	make_a_move(stack_a, stack_b, prep);
}

char	*end_move(t_lst **stack_a, t_lst **stack_b, char *line, int *i)
{
	int		set[3];
	char	prep[4];

	if (!(*stack_b) || !(*stack_b)->next)
		return (line);
	ft_bzero(prep, 4);
	see_order(*stack_b, set);
	if (set[0] > set[1] && set[0] < set[2])
		ft_strcpy(prep, "rra");
	else if (set[0] < set[2])
		ft_strcpy(prep, "ra");
	else if (set[0] < set[1])
		ft_strcpy(prep, "sa");
	if (ft_strequ(line, prep) && ft_strequ(line, "ra"))
		return (ft_strcpy(line, "rr"));
	if (ft_strequ(line, prep) && ft_strequ(line, "rra"))
		return (ft_strcpy(line, "rrr"));
	if (ft_strequ(line, prep) && ft_strequ(line, "sa"))
		return (ft_strcpy(line, "ss"));
	else if (prep[0])
		set_stack_b(stack_a, stack_b, prep, i);
	else if (!line[0] && prep[0])
		ft_strcpy(line, prep);
	return (line);
}

char	*end_to_end_stack_b(t_lst **stk_a, t_lst **stk_b, char *line, int *i)
{
	end_move(stk_a, stk_b, line, i);
	if (!line[0])
		return (ft_strcpy(line, "pa"));
	return (line);
}
