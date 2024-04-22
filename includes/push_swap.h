/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:20:53 by jlebard           #+#    #+#             */
/*   Updated: 2024/04/17 16:19:33 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct Stack
{
	int		 		data;
	int				index;
	struct Stack	*current;
	struct	Stack	*previous;
	struct	Stack	*next;
}	t_stack_node;

bool	ft_check_error_int_array(int *int_arr);
bool	chek_error_str(char *str);
t_stack_node	*stack_init(int *array, int size);
int		*split_and_check(char	*str);
size_t	pile_size(t_stack_node *stack);
size_t	stack_size(t_stack_node *stack);
bool	is_sorted(t_stack_node *stack);
void	sort_3(t_stack_node **stack);
//push
void	pa(t_stack_node **a, t_stack_node **b);
void	pb(t_stack_node **a, t_stack_node **b);
// swap
void	sa(t_stack_node **a);
void	sb(t_stack_node **b);
void	ss(t_stack_node **a, t_stack_node **b);
// rotate
void	ra(t_stack_node a);
void	rb(t_stack_node b);
void	rr(t_stack_node a, t_stack_node b);
//reverse_rotate
void	rra(t_stack_node a);
void	rrb(t_stack_node b);
void	rrr(t_stack_node a, t_stack_node b);

#endif
	