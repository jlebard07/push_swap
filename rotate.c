/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@students.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:46:24 by jlebard            #+#    #+#             */
/*   Updated: 2024/04/09 18:46:24 by jlebard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

t_stack_node	*rotate(t_stack_node *ba)
{
	t_stack_node	*ea;
	t_stack_node	*current;
	int				temp;
	
	ea = ba->previous;
	current = ea->previous;
	while(current != ba)
	{
		current->data = next->data;
		current = current->previous;
	}
	ea->data = ba->data;
	ba->data = 
	return (ba);
}