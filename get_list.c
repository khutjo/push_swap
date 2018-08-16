/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:16:17 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/16 16:46:26 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfile.h"

t_lst			*makes_nodes(int num_of_nodes)
{
	t_lst	*run;
	t_lst	*head;
	t_lst	*temp_nodes;

	run = NULL;
	head = NULL;
	while (num_of_nodes-- && (temp_nodes = (t_lst *)malloc(sizeof(t_lst))))
	{
		temp_nodes->stack = 0;
		temp_nodes->next = NULL;
		if (!head)
		{
			head = temp_nodes;
			run = head;
		}
		else
		{
			run->next = temp_nodes;
			run = run->next;
		}
	}
	return (head);
}

static	int		num_of_words_counter(char *str)
{
	int index;
	int num_of_words;

	index = 0;
	num_of_words = 0;
	while (str[index] && !ft_isdigit(str[index]))
		index++;
	while (str[index])
	{
		if (ft_isdigit(str[index]))
			num_of_words++;
		while (str[index] && ft_isdigit(str[index]))
			index++;
		while (str[index] && !ft_isdigit(str[index]))
			index++;
	}
	return (num_of_words);
}

static	int		invalid_num(int num, char c, int *state)
{
	if (num < 0 && c != '-')
	{
		*state = *state + 1;
		return (1);
	}
	return (0);
}

t_lst			*single_str(char *str, int *state)
{
	int		index;
	t_lst	*run_node;
	t_lst	*ret_head;
	int		num_of_words;

	index = 0;
	num_of_words = num_of_words_counter(str);
	ret_head = makes_nodes(num_of_words);
	while (str[index] && !ft_isdigit(str[index]))
		index++;
	run_node = ret_head;
	while (str[index])
	{
		if (str[index] != ' ')
			run_node->stack = ft_atoi(&str[index]);
		if (invalid_num(run_node->stack, str[index], state))
			return (ret_head);
		while (str[index] && str[index] != ' ')
			index++;
		while (str[index] && str[index] == ' ')
			index++;
		run_node = run_node->next;
	}
	return (ret_head);
}

t_lst			*multi_args(char **args, int num_of_args, int *state)
{
	int		index;
	int		space;
	t_lst	*run_node;
	t_lst	*ret_head;

	index = 0;
	ret_head = makes_nodes(--num_of_args);
	run_node = ret_head;
	while (args[++index])
	{
		run_node->stack = ft_atoi(args[index]);
		space = 0;
		while (args[index][space] && args[index][space] == ' ')
			space++;
		if (invalid_num(run_node->stack, args[index][space], state))
			return (ret_head);
		run_node = run_node->next;
	}
	return (ret_head);
}
