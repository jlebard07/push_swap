/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:12:19 by jlebard            #+#    #+#             */
/*   Updated: 2024/04/04 15:12:19 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

static t_stack_node	*creat_node(int n)
{
	t_stack_node	*a;

	a = malloc(sizeof(t_stack_node));
	if (!a)
		return (NULL);
	a->data = n;
	a->current = NULL;
	a->previous = NULL;
	a->next = NULL;
	return (a);
}

t_stack_node	*stack_init(int *array, int size)
{
	t_stack_node	*ba;
	t_stack_node	*ca;
	t_stack_node	*ea;
	int		i;

	if (size == 0 || array == NULL)
		return (NULL);
	i = 0;
	ca = NULL;
	ea = NULL;
	ba = creat_node(array[0]);
	if (!ba)
		return (NULL);
	ea = ba;
	while (array[i++] && i < size)
	{
		ca = creat_node(array[i]);
		if (i == 1)
			ba->next = ca;
		ca->previous = ea;
		ea->next = ca;
		ea = ca;
	}
	ba->previous = ea;
	return (ba);
}
