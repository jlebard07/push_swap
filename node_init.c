/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:49:00 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/22 09:56:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	set_pile_utils(t_stack_node *a, t_stack_node *b)
{
	current_position(a);
	current_position(b);
	target_node(a, b);
	set_price(a, b);
}
