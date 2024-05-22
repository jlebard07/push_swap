/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:14:04 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/22 12:09:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *is_cheapest)
{
	while (*a != is_cheapest->target && *b != is_cheapest)
		rr(a, b);
	current_position(*a);
	current_position(*b);
}

static void	reverse_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *is_cheapest)
{
	while (*a != is_cheapest->target && *b != is_cheapest)
		rrr(a, b);
	current_position(*a);
	current_position(*b);
}

static void	finish_rotate(t_stack_node **stack, t_stack_node *cible, char aoub)
{
	while (*stack != cible)
	{
		if (aoub == 'a')
		{
			if (cible->under_avg_rank == true)
				rra(stack);
			else
				ra(stack);
		}
		else
		{
			if(cible->under_avg_rank == true)
				rrb(stack);
			else
				rb(stack);
		}

	}
}

static void	sort_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*is_cheapest;

	is_cheapest = who_cheapest(*b);
	if (is_cheapest->under_avg_rank == true
		&& is_cheapest->target->under_avg_rank == true)
		reverse_rotate_both(a, b, is_cheapest);
	else if (is_cheapest->under_avg_rank == false
		&& is_cheapest->target->under_avg_rank == false)
		rotate_both(a, b, is_cheapest);
	finish_rotate(a, is_cheapest->target, 'a');
	finish_rotate(b, is_cheapest, 'b');
	pa(a, b);
}

void	ft_pushswap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*is_lowest;
	size_t			size_a;

	size_a = pile_size(*a);
	if (size_a > 3)
	{
		while (size_a-- > 3)
			pb(a, b);
	}
	sort_3(a);
	while (*b)
	{
		set_pile_utils(*a, *b);
		sort_nodes(a, b);
	}
	current_position(*a);
	is_lowest = find_lowest(*a);
	if(is_lowest->under_avg_rank == true)
		while (*a != is_lowest)
			rra(a);
	else
		while (*a != is_lowest)
			ra(a);
}
