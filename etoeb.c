/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etoeb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 17:07:06 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/16 17:42:32 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	set_stack_b(t_lst **stack_a, t_lst **stack_b, char *prep)
{
	if (ft_strequ(prep, "sa"))
		ft_strcpy(prep, "sb");
	if (ft_strequ(prep, "ra"))
		ft_strcpy(prep, "rb");
	if (ft_strequ(prep, "rra"))
		ft_strcpy(prep, "rrb");
	ft_putstr(prep);
	ft_putchar('\n');
	make_a_move(stack_a, stack_b, prep);
}

char	*end_move(t_lst **stack_a, t_lst **stack_b, char *line)
{
	int		set[3];
	char	prep[4];

	ft_bzero(prep, 4);
	if (!(*stack_b) || !(*stack_b)->next)
		return (line);
	see_order(*stack_b, set);
	if (set[0] < set[1])
		ft_strcpy(prep, "sa");
	else if (set[0] > set[1] && set[0] < set[2])
		ft_strcpy(prep, "rra");
	else if (set[0] < set[2])
		ft_strcpy(prep, "ra");
	if (ft_strequ(prep, line))
	{
		if (ft_strequ(line, "sa"))
			return (ft_strcpy(line, "ss"));
		if (ft_strequ(line, "ra"))
			return (ft_strcpy(line, "rr"));
		if (ft_strequ(line, "rra"))
			return (ft_strcpy(line, "rrr"));
	}
	(prep[0] ? set_stack_b(stack_a, stack_b, prep) : 0);
	(!line[0] && prep[0] ? (ft_strcpy(line, prep)) : 0);
	return (line);
}

char	*end_to_end_stack_b(t_lst **stack_a, t_lst **stack_b, char *line)
{
	end_move(stack_a, stack_b, line);
	if (!line[0])
		return (ft_strcpy(line, "pa"));
	return (line);
}
