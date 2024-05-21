/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:15:23 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/21 16:33:32 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	swap(t_stack_node **stack)
{
	if (*stack == NULL || pile_size(*stack) == 1)
		return ;
	*stack = (*stack)->next;
	(*stack)->previous->previous = *stack;
	(*stack)->previous->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->previous = (*stack)->previous;
	(*stack)->next = (*stack)->previous;
	(*stack)->previous = NULL;
}

void	sa(t_stack_node **a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack_node **b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}
