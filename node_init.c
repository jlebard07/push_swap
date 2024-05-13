/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:49:00 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/13 14:10:02 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	set_pile_utils(t_stack_node *a, t_stack_node *b)
{
	current_position(a);
	current_position(b);
	target_node(a, b);
	set_price(a, b);
	who_cheapest(b);
}
