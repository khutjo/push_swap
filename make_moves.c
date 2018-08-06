/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:15:47 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/06 18:48:06 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfile.h"

void	move_ss(t_lst **head)
{
	t_lst	*node;

	if (!(*head) || !(*head)->next)
		return ;
	node = (*head)->next;
	(*head)->next = node->next;
	node->next = (*head);
	(*head) = node;
}

void	move_rr(t_lst **head)
{
	t_lst	*node;

	if (!(*head) || !(*head)->next)
		return ;
	node = (*head);
	while (node->next)
		node = node->next;
	node->next = (*head);
	(*head) = (*head)->next;
	node = node->next;
	node->next = NULL;
}

void	move_rrr(t_lst	**head)
{
	t_lst	*node_end;
	t_lst	*node_before_end;

	if (!(*head) || !(*head)->next)
		return ;
	node_end = (*head)->next;
	node_before_end = (*head);
	while (node_end->next)
	{
		node_before_end = node_before_end->next;
		node_end = node_end->next;
	}
	node_before_end->next = NULL;
	node_end->next = (*head);
	(*head) = node_end;
}
void	move_pp(t_lst **head_of_src, t_lst	**head_of_dest)
{
	t_lst	*temp_node;

	if ((*head_of_src))
	{
		temp_node = (*head_of_src);
		(*head_of_src) = (*head_of_src)->next;
		temp_node->next = (*head_of_dest);
		(*head_of_dest) = temp_node;
	}
}

void	make_a_move(t_lst **stack_a, t_lst **stack_b, int move)
{
	if (move == 0)
		move_ss(stack_a);
	if (move == 1)
		move_ss(stack_b);
	if (move == 2)
	{
		move_ss(stack_a);
		move_ss(stack_b);
	}
	if (move == 3)
		move_rr(stack_a);
	if (move == 4)
		move_rr(stack_b);
	if (move == 5)
	{
		move_rr(stack_a);
		move_rr(stack_b);
	}
	if (move == 6)
		move_rrr(stack_a);
	if (move == 7)
		move_rrr(stack_b);
	if (move == 8)
	{
		move_rrr(stack_a);
		move_rrr(stack_b);
	}
	if (move == 9)
		move_pp(stack_a, stack_b);
	if (move == 10)
		move_pp(stack_b, stack_a);
}
