/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:52:17 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/21 14:04:58 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

bool	is_sorted(t_stack_node *stack)
{
	int				i;

	i = 0;
	while (stack->next != NULL)
	{
		i = stack->data;
		stack = stack->next;
		if (i > stack->data)
			return (false);
	}
	return (true);
}

void	sort_3(t_stack_node **stack)
{
	t_stack_node	*highest;

	highest = find_highest(*stack);
	if (*stack == highest)
		ra(stack);
	else if ((*stack)->next == highest)
		rra(stack);
	if ((*stack)->data > (*stack)->next->data)
		sa(stack);
}
