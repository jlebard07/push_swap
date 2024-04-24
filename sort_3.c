/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:52:17 by jlebard           #+#    #+#             */
/*   Updated: 2024/04/24 14:32:11 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_sorted(t_stack_node *stack)
{
	int				i;

	while (stack->next != NULL)
	{
		i = stack->data;
		stack = stack->next;
		if (i < stack->data)
			return (false);
	}
	return (true);
}

static t_stack_node	*highest_data(t_stack_node *stack)
{
	t_stack_node	*highest;
	int				max;

	max = INT_MIN;
	highest = NULL;
	while (stack->next != NULL)
	{
		if (stack->data > max)
		{
			max = stack->data;
			highest = stack;
		}
		stack = stack->next;
	}
	return (highest);
}

void	sort_3(t_stack_node **stack)
{
	t_stack_node	*highest;

	highest = highest_data(*stack);
	if (stack == highest)
		ra(stack);
	else if ((*stack)->next == highest)
		rra(stack);
	if ((*stack)->data > (*stack)->next->data)
		sa(stack);
}
