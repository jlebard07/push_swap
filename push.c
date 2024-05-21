/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:20:35 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/21 16:05:55 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	push(t_stack_node **src_pile, t_stack_node **dest_pile)
{
	t_stack_node	*temp;

	if (*src_pile == NULL)
		return ;
	temp = *src_pile;
	*src_pile = (*src_pile)->next;
	if (*src_pile)
		(*src_pile)->previous = NULL;
	temp->previous = NULL;
	if (*dest_pile == NULL)
	{
		*dest_pile = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *dest_pile;
		temp->next->previous = temp;
		*dest_pile = temp;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	ft_putstr_fd("pb\n", 1);
}
