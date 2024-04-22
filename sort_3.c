/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:52:12 by jlebard            #+#    #+#             */
/*   Updated: 2024/04/17 18:52:12 by jlebard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_sorted(t_stack_node *stack)
{
	t_stack_node	temp;
	int				i;

	temp = stack;
	while (temp->next != NULL)
	{
		i = temp->data;
		temp = temp->next;
		if (i < temp->data)
			return (false);
	}
	return (true);
}

static t_stack_node	*highest_data(t_stack_node *stack)
{
	t_stack_node	temp;
	t_stack_node	highest;
	int				max;

	max = INT_MIN;
	highest = NULL;
	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->value > max)
		{
			max = temp->value;
			highest = temp;
		}
		temp = temp->next;
	}
	return (highest);
}

void	sort_3(t_stack_node **stack)
{
	t_stack_node	*highest;
	
	highest = highest_data(*stack);
	if (stack == highest)
		ra(*stack);
	else if ((*stack)->next == highest)
		rra(stack);
	if ((*stack)->data > (*stack)->next->data)
		sa(stack);
}
