/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:30:18 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/21 11:54:54 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

t_stack_node	*who_cheapest(t_stack_node *stack)
{
	while (stack && stack->cheapest == false)
		stack = stack->next;
	return (stack);
}

void	put_highest_at_end(t_stack_node *stack)
{
	t_stack_node	*highest;
	t_stack_node	*last;
	int				i;

	i = INT_MIN;
	last = find_last(stack);
	highest = highest_data(stack);
	highest->previous->next = highest->next;
	highest->next->previous = highest->previous;
	highest->next = NULL;
	highest->previous = last;
	last->next = highest;
}

t_stack_node	*find_lowest(t_stack_node *stack)
{
	t_stack_node	*lowest;
	int				i;

	i = INT_MAX;
	while (stack)
	{
		if ((stack)->data < i)
		{
			lowest = stack;
			i = stack->data;
		}
		stack = stack->next;
	}
	return (lowest);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}
