/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:44:18 by marvin            #+#    #+#             */
/*   Updated: 2024/05/23 13:44:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	set_index(t_stack_node *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = pile_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->under_median = true;
		else
			stack->under_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*temp;
	t_stack_node	*target;
	long			smallest_bigger;

	while (b)
	{
		smallest_bigger = LONG_MAX;
		temp = a;
		while (temp)
		{
			if (temp->value > b->value
			&& temp->value < smallest_bigger)
			{
				smallest_bigger = temp->value;
				target = temp;
			}
			temp = temp->next;
		}
		if (smallest_bigger == LONG_MAX)
			b->target = find_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	sa;
	int	sb;

	sa = pile_size(a);
	sb = pile_size(b);
	while (b)
	{
		b->price = b->index;
		if (!(b->under_median))
			b->price = sb - b->index;
		if (!(b->target->under_median))
			b->price += sa - b->target->index;
		else
			b->price += b->target->index;
		b = b->next;
	}	
}

void	set_cheapest(t_stack_node *b)
{
	int				i;
	t_stack_node	*cheapest;

	i = INT_MAX;
	cheapest = NULL;
	while (b)
	{
		if (i > b->price)
		{
			i = b->price;
			cheapest = b;
		}
		b->cheapest = false;
		b = b->next;
	}
	cheapest->cheapest = true;
}

void	set_nodes(t_stack_node *a, t_stack_node *b)
{
	set_index(a);
	set_index(b);
	set_target(a, b);
	set_price(a, b);
	set_cheapest(b);
}
