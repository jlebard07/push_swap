/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:13:21 by jlebard           #+#    #+#             */
/*   Updated: 2024/04/22 16:00:26 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	pile_size(t_stack_node **stack)
{
	t_stack_node	*temp;
	size_t			i;

	if (stack == NULL)
		return (0);
	i = 1;
	temp = *stack;
	while (temp->next != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	current_position(t_stack_node **stack)
{
	t_stack_node	*temp;
	int				i;
	int				avg_rank;

	avg_rank = pile_size(stack) / 2;
	if (!stack)
		return ;
	temp = *stack;
	i = 0;
	while (temp->next != NULL)
	{
		temp->index = i;
		if (i < avg_rank)
			temp->under_avg_rank = true;
		else
			temp->under_avg_rank = false;
		i++;
		temp = temp->next;
	}
}

void	target(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tempa;
	t_stack_node	*tempb;
	long int		diff_match;

	tempa = *a;
	tempb = *b;
	diff_match = LONG_MAX;
	while (tempb->next!= NULL)
	{
		while (tempa->next != NULL)
		{
			if (0 < (long int)tempb->data - (long int)tempa->data < diff_match)
			{
				(long int)tempb->data - (long int)tempa->data;
				tempb->target = tempa;
			}
			tempa = tempb->next;
		}
		tempb = tempb->next;
		tempa = *a;
	}
}

void	set_price(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp;

	temp = *b;
	while (temp->next != NULL)
	{
		if (temp->under_avg_rank == true && temp->target->under_avg_rank == true)
			temp->price = temp->index + temp->target->index;
		else if (temp->under_avg_rank == false && temp->target->under_avg_rank == true)
			temp->price = pile_size(b) - temp->index + 1 + temp->target->index;
		else if (temp->under_avg_rank == true && temp->target->under_avg_rank == false)
			temp->price = temp->index + 1 + pile_size(a)temp->target->index;
		else if (pile_size(b) - temp->index == pile_size(a) - temp->target->index)
			temp->price = pile_size(b) - temp->index + 1 + pile_size(a) - temp->target->index;
		else
			temp->price = pile_size(b) - temp->index + 2 + pile_size(a) - temp->target->index;
	}
}

void	who_cheapest(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*cheapest;
	int				i;

	temp = *stack;
	cheapest = NULL;
	i = INT_MAX;
	while (temp->next != NULL)
	{
		if (i > temp->price)
		{
			cheapest = temp;
			i = temp->price;
		}
		temp = temp->next;
	}
	cheapest->cheapest = true;
}
