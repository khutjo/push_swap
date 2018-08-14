/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:16:17 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/14 10:54:24 by kmaputla         ###   ########.fr       */
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

t_lst			*single_str(char *str)
{
	int		index;
	t_lst	*run_node;
	t_lst	*ret_head;
	int		num_of_words;

	index = -1 + ft_strlen(str);;
	num_of_words = num_of_words_counter(str);
	ret_head = makes_nodes(num_of_words);
	run_node = ret_head;
	while (run_node)
	{
		while ((!ft_isdigit(str[index]) && str[index] != '-' &&\
				str[index] != '+') && index >= 0)
			index--;
		while ((ft_isdigit(str[index]) || str[index] == '-' ||\
				str[index] == '+') && index >= 0)
			index--;
		if (index >= 0)
			run_node->stack = ft_atoi(&str[index]);
		run_node = run_node->next;
	}
	return (ret_head);
}

t_lst			*multi_args(char **args, int num_of_args)
{
	int		index;
	t_lst	*run_node;
	t_lst	*ret_head;

	index = num_of_args;
	ret_head = makes_nodes(--num_of_args);
	run_node = ret_head;
	while (--index > 0)
	{
		run_node->stack = ft_atoi(args[index]);
		run_node = run_node->next;
	}
	return (ret_head);
}