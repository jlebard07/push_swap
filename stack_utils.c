/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:58:56 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/28 14:58:56 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./includes/push_swap.h"

t_stack_node	*find_last(t_stack_node *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack_node	*find_biggest(t_stack_node *stack)
{
	int				i;
	t_stack_node	*biggest;

	i = INT_MIN;
	biggest = NULL;
	while (stack)
	{
		if (stack->value > i)
		{
			i = stack->value;
			biggest = stack;
		}
		stack = stack->next;
	}
	return (biggest);
}

t_stack_node	*find_smallest(t_stack_node *stack)
{
	int				i;
	t_stack_node	*smallest;

	i = INT_MAX;
	smallest = NULL;
	while (stack)
	{
		if (i > stack->value)
		{
			i = stack->value;
			smallest = stack;
		}
		stack = stack->next;
	}
	return (smallest);
}

int	pile_size(t_stack_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_stack_node	*who_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheapest;

	if (!stack)
		return (NULL);
	while (!(stack->cheapest))
		stack = stack->next;
	cheapest = stack;
	return (cheapest);
}
