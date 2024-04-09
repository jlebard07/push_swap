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
	t_stack_node	*current;
	int				temp;
	int				temp2;
	int				last_data;
	
	current = ba->previous;
	last_data = ba->previous->data;
	temp2 = NULL;
	while(current != ba)
	{
		if (temp2 != NULL)
			temp = temp2;
		else 
			temp = ba->data;
		temp2 = current->data;
		current->data = temp;
		current = current->previous;
	}
	ba->data = last_data;
	return (ba);
}