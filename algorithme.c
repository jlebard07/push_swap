/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:17:32 by jlebard           #+#    #+#             */
/*   Updated: 2024/04/22 14:05:00 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_till_3(t_stack_node **a, t_stack_node **b)
{
	size_t	size;

	size = pile_size(*a);
	if (size < 3)
		return ;
	while (size > 3)
	{
		push_b(a, b);
		size = pile_size(a);
	}
}
