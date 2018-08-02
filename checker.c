/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 08:38:15 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/02 17:09:34 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>

void	swap(char *str)
{
	int		index;
	char	temp;

	index = 0;
	index = ft_strlen(str);
	if (index > 0)
	{
		temp = str[0];
		str[0] = str[1];
		str[1] = temp;
	}
}

void	push(char *a, char *b)
{
	int		i;
	char	temp_a;
	char	temp_b;

	i = 0;
	if (!a[0])
		return ;
	temp_a = a[0];
	while (a[++i])
		a[-1 + i] = a[i];
	a[--i] = '\0';
	i = ft_strlen(b);
	while (i > 0)
	{
		temp_b = b[-1 + i];
		b[i] = temp_b;
		i--;
	}
	b[i] = temp_a;
}

void	rot_forwards(char *str)
{
	int		index;
	char	temp;


	index = 0;
	temp = str[index];
	while (str[++index])
	{
		str[-1 + index] = str[index];
	}
	str[--index] = temp;
}

void	rot_backwards(char *str)
{
	int		index;
	char	temp;


	index = ft_strlen(str);
	temp = str[--index];
	while (index > 0)
	{
		str[index] = str[-1 + index];
		index--;
	} 
	str[index] = temp;
}

int		chack(char *stack_a, char *stack_b)
{
	int i;

	i = 1;
	if (stack_b[0])
		return (1);
	while (stack_a[i])
	{
		if (stack_a[-1 + i] > stack_a[i])
			return (1);
		i++;
	}
	return (0);
}

int main(int k, char **stack_a)
{
	char *stack_b;
	char input[4];

	if (k != 2)
		return (0);
	stack_b = ft_strnew(ft_strlen(stack_a[1]));
	printf("%s === %s\n", stack_a[1], stack_b);
	while (chack(stack_a[1], stack_b))
	{
		ft_bzero(input, 4);
		scanf("%s", input);
		if (ft_strequ(input, "sa"))
			swap(stack_a[1]);
		else if (ft_strequ(input, "sb"))
			swap(stack_b);
		else if (ft_strequ(input, "ss"))
		{
			swap(stack_a[1]);
			swap(stack_b);
		}
		else if (ft_strequ(input, "pa"))
			push(stack_a[1], stack_b);
		else if (ft_strequ(input, "pb"))
			push(stack_b, stack_a[1]);
		else if (ft_strequ(input, "ra"))
			rot_forwards(stack_a[1]);
		else if (ft_strequ(input, "rb"))
			rot_forwards(stack_b);
		else if (ft_strequ(input, "rr"))
		{
			rot_forwards(stack_b);
			rot_forwards(stack_a[1]);
		}
		else if (ft_strequ(input, "ab"))
			rot_forwards(stack_a[1]);
		printf("%s === %s\n", stack_a[1], stack_b);
	}
	return (0);
}	
