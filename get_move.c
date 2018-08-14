/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:32:45 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/14 10:32:11 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfile.h"

int		error_return(void)
{
	ft_putstr("Error");
	return (1);
}

int		nums_with_signs(char *str, int index)
{
	if (str[index] == '-' || str[index] == '+')
		if (ft_isdigit(str[1 + index]))
			return (0);
	if (!ft_isdigit(str[index]))
		return (1);
	return (1);
}

int		varify(char **str, int argi)
{
	int i_y;
	int i_x;
	int find_a_digit;

	i_y = 0;
	find_a_digit = 0;
	if (argi < 2)
		return (error_return());
	while (str[++i_y])
	{
		i_x = -1;
		while (str[i_y][++i_x])
		{
			if (!ft_isdigit(str[i_y][i_x]) && str[i_y][i_x] != ' ' &&
					nums_with_signs(str[i_y], i_x))
				return (error_return());
			if (str[i_y][i_x] == ' ' && argi > 2)
				return (error_return());
			if (ft_isdigit(str[i_y][i_x]))
				find_a_digit++;
		}
	}
	if (find_a_digit < 1)
		return (error_return());
	return (0);
}

int		check(t_lst *stack_a, t_lst *stack_b, int state)
{
	int i;

	if (!stack_a || stack_b)
	{
		if (!state)
			write(1, "KO\n", 3);
		return (0);
	}
	i = stack_a->stack;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (i > stack_a->stack)
		{
			if (!state)
				write(1, "KO\n", 3);
			return (0);
		}
		i = stack_a->stack;
		stack_a = stack_a->next;
	}
	if (!state)
		write(1, "OK\n", 3);
	return (1);
}

void	play_moves(t_lst **stack_a, t_lst **stack_b)
{
	char	*line;

	line = NULL;
	if (check(*stack_a, *stack_b, 1))
		return ;
	while (get_next_line(&line))
	{
		make_a_move(stack_a, stack_b, line);
		if (check(*stack_a, *stack_b, 1))
			return ;
	}
}
