/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:30:18 by jlebard           #+#    #+#             */
/*   Updated: 2024/04/24 14:31:35 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_node	*who_cheapest(t_stack_node *stack)
{
	while (stack && stack->cheapest == false)
		stack = stack->next;
	return (stack);
}

t_stack_node	*find_lowest(t_stack_node *stack)
{
	t_stack_node	*lowest;
	int				i;

	i = INT_MAX;
	while (stack)
	{
		if (stack->data < i)
		{
			lowest = stack;
			i = stack->data;
		}
		stack = stack->next;
	}
	return (lowest);
}
