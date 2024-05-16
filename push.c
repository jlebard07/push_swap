/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:20:35 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/16 17:46:22 by jlebard          ###   ########.fr       */
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
	(*src_pile)->previous = NULL;
	if (*dest_pile)
	{
		temp->next = *dest_pile;
		(*dest_pile)->previous = temp;
		temp->previous = NULL;
		*dest_pile = temp;
	}
	else
	{
		temp->next = NULL;
		temp->previous = NULL;
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
