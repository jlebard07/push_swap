/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:13:21 by jlebard           #+#    #+#             */
/*   Updated: 2024/04/17 15:17:15 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	pile_size(t_stack_node *stack)
{
	t_stack_node	*temp;
	size_t			i;

	if (stack == NULL)
		return (0);
	i = 1;
	temp = stack;
	while (temp->next != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
