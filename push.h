/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:39:16 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/20 10:39:34 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H
# include "libfile.h"

char	*tactic(t_lst **stack_a, t_lst **stack_b, char *line, int *i);
void	see_order(t_lst *stack, int *set);
char	*end_to_end_stack_a(t_lst *stack, char *line);
char	*end_to_end_stack_b(t_lst **stk_a, t_lst **stk_b, char *line, int *i);

#endif
