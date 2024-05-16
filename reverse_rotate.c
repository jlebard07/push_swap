/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:23:29 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/16 17:53:36 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*temp;

	if (*stack == NULL || pile_size(*stack) == 1)
		return ;
	temp = *stack;
	*stack = find_last(*stack);
	(*stack)->previous->next = NULL;
	(*stack)->previous = NULL;
	(*stack)->next = temp;
	temp->previous = *stack;
}

void	rra(t_stack_node **a)
{
	reverse_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack_node **b)
{
	reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rra\n", 1);
}
