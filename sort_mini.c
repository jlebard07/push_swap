/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:02:44 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/28 15:02:44 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

bool	is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	sort_3(t_stack_node **a)
{
	if (*a == find_biggest(*a))
		ra(a);
	else if ((*a)->next == find_biggest(*a))
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}
