/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:23:29 by jlebard           #+#    #+#             */
/*   Updated: 2024/04/10 13:24:27 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_node	*reverse_rotate(t_stack_node *ba)
{
	t_stack_node	*current;
	int				temp;
	int				temp2;
	int				last_data;

	current = ba->next;
	last_data = ba->next->data;
	temp2 = NULL;
	while (current != ba)
	{
		if (temp2 != NULL)
			temp = temp2;
		else
			temp = ba->data;
		temp2 = current->data;
		current->data = temp;
		current = current->next;
	}
	ba->data = last_data;
	return (ba);
}
