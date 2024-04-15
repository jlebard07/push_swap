/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:20:35 by jlebard           #+#    #+#             */
/*   Updated: 2024/04/12 11:20:27 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_stack_node **src_pile, t_stack_node dest_pile)
{
	t_stack_node	*temp;

	if(*src_pile == NULL)
		return ;
	temp = (*src_pile)->next;
	(*src_pile)->next = *dest;
	*dest = *src;
	*src = temp;	
}

void	push_a(t_stack_node **a, t_stack_node **b)
{
	push(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	ft_putstr_fd("pb\n", 1);
}
