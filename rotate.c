/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:14:05 by jlebard           #+#    #+#             */
/*   Updated: 2024/04/10 13:14:18 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*bottom;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp ->next;
	bottom = temp;
	temp = *stack;
	*stack = (*stack)->next;
	bottom->next = temp;
	temp->next = NULL;
}

void	ra(t_stack_node a)
{
	rotate(*a);
	ft_putstr_fd("ra", 1);
}

void	rb(t_stack_node b)
{
	rotate(*b);
	ft_putstr_fd("rb", 1);
}

void	rr(t_stack_node a, t_stack_node b)
{
	rotate(*a);
	rotate(*b);
	ft_putstr_fd("rr", 1);
}
