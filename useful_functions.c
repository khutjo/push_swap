/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 12:18:38 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/06 15:13:39 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfile.h"

void		ft_putstr(char *str)
{
	while (*str)
		write(1, &*str++, 1);
}

int			ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		 return (1);
	return (0);
}

static int	check(char *str)
{
	int		i;
	int		sk;
	char	*skip;

	i = -1;
	sk = 0;
	skip = "\t\v\f\r\n ";
	while (++i < 7)
		if (str[sk] == skip[i])
		{
			sk++;
			i = -1;
		}
	return (sk);
}

int			ft_atoi(const char *str)
{
	int		index;
	long	num;
	int		sign;

	num = 0;
	sign = 0;
	index = check((char *)str);
	if (str[index] == '-' || str[index] == '+')
		sign = str[index++];
	while (str[index] >= '0' && str[index] <= '9')
	{
		num *= 10;
		num += str[index] - '0';
		index++;
		if (num < 0 && sign == '-')
			return (0);
		else if (num < 0)
			return (-1);
	}
	if (sign == '-')
		num *= -1;
	return ((int)num);
}

int		varify(char	**str, int argi)
{
	int index_y;
	int index_x;
	int find_a_digit;

	index_y = 0;
	find_a_digit = 0;
	while (str[++index_y])
	{
		index_x = -1;
		while (str[index_y][++index_x])
		{
			if (!ft_isdigit(str[index_y][index_x]) &&\
				   str[index_y][index_x] != ' ')
				return (1);
			if (str[index_y][index_x] == ' ' && argi > 2)
				return (1);
			if (ft_isdigit(str[index_y][index_x]))
				find_a_digit++;
		}
	}
	if (find_a_digit < 1)
		return (1);
	return (0);
}
