/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 09:29:49 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/04 18:17:26 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int	put_to_arrey(int **num_arrey, char *str, int index)
{
	int i;

	i = 0;
	while (str[i] == ' ' && str[i])
		i++;
	while (str[i])
	{
		(*num_arrey)[index++] = ft_atoi(&str[i]);
		while (str[i] != ' ' && str[i])
			i++;
		while (str[i] == ' ' && str[i])
			i++;
	}
	return (index);
}

int *join(char **str, int *len)
{
	int i;
	int index;
	int	*num_arrey;

	i = 0;
	index = 0;
	while (str[++i])
		*len += num_of_words(str[i], ' ');
	num_arrey = (int *)malloc(sizeof(char) * *len);
	i = 0;
	while (str[++i])
		index = put_to_arrey(&num_arrey, str[i], index);
	return (num_arrey);
}
int	varify(char **str)
{
	int i;
	int j;

	i = 0;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (!ft_isdigit(str[i][j]) && str[i][j] != ' ')
				return (1);
		}
	}
	return (0);
}

int	main(int argi, char **args)
{
	int len;
	int index;
	int	*stack_a;
	int *stack_b;

	len = 0;
	index = -1;
	if (argi < 2 || varify(args))
		return (0);
	stack_a = join(args, &len);
	stack_b = (int *)malloc(sizeof(int));
	while (++index < len)
		printf("== %d ==\n", temp[index]);
	free(temp);
	return (0);
}
