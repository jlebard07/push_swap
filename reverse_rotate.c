/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:23:29 by jlebard           #+#    #+#             */
/*   Updated: 2024/04/16 11:32:08 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*bottom;
	t_stack_node	*temp2;

	temp = *stack;
	temp2 = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	bottom = temp;
	temp = bottom->previous;
	*stack = bottom;
	(*stack)->next = temp2;
	temp->next = NULL;
}

void	rra(t_stack_node **a)
{
	reverse_rotate(a);
	ft_putstr_fd("rra", 1);
}

void	rrb(t_stack_node **b)
{
	reverse_rotate(b);
	ft_putstr_fd("rrb", 1);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rra", 1);
}