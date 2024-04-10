/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:15:23 by jlebard           #+#    #+#             */
/*   Updated: 2024/04/10 13:20:07 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_node	*swap(t_stack_node *a)
{
	int	i;

	if (a->data == NULL)
		return (a);
	a->data = i;
	a->data = a->next->data;
	a->next->data = i;
	return (a);
}
