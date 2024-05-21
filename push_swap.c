/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:14:04 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/21 14:18:10 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	finish_rotate(t_stack_node **stack, t_stack_node *cible, char aoub)
{
	while (*stack != cible)
	{
		if (aoub == 'a')
			ra(stack);
		else
			rb(stack);
	}
}

static void	sort_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*is_cheapest;

	is_cheapest = who_cheapest(*b);
	if (is_cheapest->under_avg_rank == true
		&& is_cheapest->target->under_avg_rank == true)
	{
		while (*b != is_cheapest || *a != is_cheapest->target)
			rr(a, b);
	}
	else if (is_cheapest->under_avg_rank == false
		&& is_cheapest->target->under_avg_rank == false)
	{
		while (*b != is_cheapest || *a != is_cheapest->target)
			rrr(a, b);
	}
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
		put_highest_at_end(a);
	while (size_a-- > 3)
		pb(a, b);
	sort_3(a);
	while (*b)
	{
		set_pile_utils(*a, *b);
		sort_nodes(a, b);
	}
	is_lowest = find_lowest(*a);
	while (*a != is_lowest)
	{
		ra(a);
	}
}
