/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:39:16 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/16 17:25:09 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H
# include "libfile.h"

void	see_order(t_lst *stack, int *set);
char	*end_to_end_stack_a(t_lst *stack, char *line);
char	*end_to_end_stack_b(t_lst **stack_a, t_lst **stack_b, char *line);

#endif
