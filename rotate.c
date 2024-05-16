/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:14:05 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/16 17:53:15 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*bottom;

	if (*stack == NULL || pile_size(*stack) == 1)
		return ;
	temp = *stack;
	bottom = find_last(*stack);
	*stack = (*stack)->next;
	bottom->next = temp;
	temp->next = NULL;
	temp->previous = bottom;
	(*stack)->previous = NULL;
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
