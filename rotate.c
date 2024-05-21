/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:14:05 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/21 15:17:05 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (*stack == NULL || pile_size(*stack) == 1)
		return ;
	last = find_last(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	last->next->previous = last;
	last->next->next = NULL;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack_node **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}
