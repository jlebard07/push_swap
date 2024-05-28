/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:00:19 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/28 15:00:19 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	push(t_stack_node **dest, t_stack_node **source)
{
	t_stack_node	*temp;

	if (!*source)
		return ;
	temp = *source;
	if (temp->next)
	{
		temp->next->previous = NULL;
		*source = temp->next;
	}
	else
		*source = NULL;
	if (*dest)
	{
		temp->next = *dest;
		(*dest)->previous = temp;
		*dest = temp;
	}
	else
	{
		*dest = temp;
		temp->next = NULL;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
