/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfile.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 09:32:44 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/08 08:53:17 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFILE_H
# define LIBFILE_H
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef	struct		s_lst
{
	int				stack;
	struct s_lst	*next;
}					t_lst;

//void				ft_putstr(char *str);
//int					ft_isdigit(char	c);
//int					ft_atoi(const char *s);
int					varify(char **str, int argi);
int					check(t_lst *stack_a, t_lst *stack_b, int state);
void				play_moves(t_lst **stack_a, t_lst **stack_b);
void				make_a_move(t_lst **stack_a, t_lst **stack_b, char *line);
t_lst				*multi_args(char **str, int num_of_args);
t_lst				*single_str(char *str);
#endif
