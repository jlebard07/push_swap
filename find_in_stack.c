/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:30:18 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/22 12:11:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

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

t_stack_node	*find_highest(t_stack_node *stack)
{
	t_stack_node	*highest;
	int				max;

	max = INT_MIN;
	highest = NULL;
	while (stack)
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

t_stack_node	*find_last(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
