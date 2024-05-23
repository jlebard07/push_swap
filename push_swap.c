/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:37:22 by marvin            #+#    #+#             */
/*   Updated: 2024/05/23 13:37:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b,
						t_stack_node *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rr(a, b);
	set_index(*a);
	set_index(*b);
}

static void	reverse_rotate_both(t_stack_node **a, t_stack_node **b,
						t_stack_node *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rrr(a, b);
	set_index(*a);
	set_index(*b);
}

static void	finish_rotation(t_stack_node **stack, t_stack_node *set_first,
						bool a)
{
	while (*stack != set_first)
	{
		if (a)
		{
			if (set_first->under_median)
				ra(stack);
			else
				rra(stack);
		}
		else
			if (set_first->under_median)
				rb(stack);
			else
				rrb(stack);
	}
}

static void	sort_and_push(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *cheapest;

	cheapest = who_cheapest(*b);
	if (cheapest->under_median && cheapest->target->under_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->under_median)
			&& !(cheapest->target->under_median))
		reverse_rotate_both(a, b, cheapest);
	finish_rotation(b, cheapest, false);
	finish_rotation(a, cheapest->target, true);
	pa(a, b);
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	int				sa;
	t_stack_node	*smallest;
	
	sa = pile_size(*a);
	while (sa-- > 3)
		pb(a ,b);
	sort_3(a);
	while (*b)
	{
		set_nodes(*a, *b);
		sort_and_push(a, b);
	}
	set_index(*a);
	smallest = find_smallest(*a);
	if (smallest->under_median)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}
