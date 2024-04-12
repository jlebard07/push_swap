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

static void	push(t_stack_node *a, t_stack_node *b)
{
	int	i;

	if (a == NULL || b == NULL)
		return ;
	a->next = b;
	a->previous = b->previous;
	a->index = 1;
	b->index = 2;
	
}
