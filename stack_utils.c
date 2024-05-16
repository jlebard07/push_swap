/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:13:21 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/16 15:22:47 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

size_t	pile_size(t_stack_node *stack)
{
	size_t			i;

	if (stack == NULL)
		return (0);
	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	current_position(t_stack_node *stack)
{
	int				i;
	int				avg_rank;

	avg_rank = pile_size(stack) / 2;
	if (!stack)
		return ;
	i = 0;
	while (stack)
	{
		stack->index = i;
		if (i < avg_rank)
			stack->under_avg_rank = true;
		else
			stack->under_avg_rank = false;
		i++;
		stack = stack->next;
	}
}

void	target_node(t_stack_node *a, t_stack_node *b)
{
	long int		diff_match;
	t_stack_node	*save_start;

	save_start = a;
	diff_match = LONG_MAX;
	while (b)
	{
		while (a)
		{
			if (0 < (long int)a->data - (long int)b->data < diff_match)
			{
				diff_match = (long int)a->data - (long int)b->data;
				b->target = a;
			}
			a = a->next;
		}
		b = b->next;
		a = save_start;
	}
}

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int				sa;
	int				sb;

	sa = pile_size(a);
	sb = pile_size(b);
	while (b)
	{
		if (b->under_avg_rank == true
			&& b->target->under_avg_rank == true)
			b->price = b->index + b->target->index;
		else if (b->under_avg_rank == false
			&& b->target->under_avg_rank == true)
			b->price = sb - b->index + 1 + b->target->index;
		else if (b->under_avg_rank == true
			&& b->target->under_avg_rank == false)
			b->price = b->index + 1 + sa - b->target->index;
		else if (sb - b->index == sa - b->target->index)
			b->price = sb - b->index + 1 + sa - b->target->index;
		else
			b->price = sb - b->index + 2 + sa - b->target->index;
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheapest;
	int				i;

	cheapest = NULL;
	i = INT_MAX;
	while (stack)
	{
		if (i > stack->price)
		{
			cheapest = stack;
			i = stack->price;
		}
		stack = stack->next;
	}
	cheapest->cheapest = true;
}
