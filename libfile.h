/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfile.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 09:32:44 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/16 17:26:29 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFILE_H
# define LIBFILE_H
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef	struct		s_lst
{
	int				pos;
	int				stack;
	struct s_lst	*next;
}					t_lst;

int					error_return(void);
int					set_order(t_lst	*stack);
int					varify(char **str, int argi);
int					check(t_lst *stack_a, t_lst *stack_b, int state);
int					play_moves(t_lst **stack_a, t_lst **stack_b);
void				make_a_move(t_lst **stack_a, t_lst **stack_b, char *line);
t_lst				*multi_args(char **str, int num_of_args, int *state);
t_lst				*single_str(char *str, int *state);

#endif
