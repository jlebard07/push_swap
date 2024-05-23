/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:12:36 by marvin            #+#    #+#             */
/*   Updated: 2024/05/23 13:12:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*second;
	
	if (!*stack || pile_size(*stack) == 1)
		return ;
	last = find_last(*stack);
	second = (*stack)->next;
	last->next = *stack;
	(*stack)->previous = last;
	second->previous = NULL;
	(*stack)->next = NULL;
	*stack = second;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
