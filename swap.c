/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:15:23 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/13 14:21:25 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	swap(t_stack_node *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

void	sa(t_stack_node **a)
{
	swap(*a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack_node **b)
{
	swap(*b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(*a);
	swap(*b);
	ft_putstr_fd("ss\n", 1);
}
