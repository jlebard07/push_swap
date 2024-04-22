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

void	target_node(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tempa;
	t_stack_node	*tempb;
	long int		diff_match;

	tempa = *a;
	tempb = *b;
	while (tempb->next!= NULL)
	{
		while (tempa->next != NULL)
		{
			tempb->value - tempa
		}
	}
}
