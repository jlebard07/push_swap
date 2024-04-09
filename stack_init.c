/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_inti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:12:19 by jlebard            #+#    #+#             */
/*   Updated: 2024/04/04 15:12:19 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

static stack	*create_stack(int n)
{
	stack	*a;

	a = malloc(sizeof(stack));
	if (!a)
		return (NULL);
	a->data = n;
	a->current = NULL;
	a->previous = NULL;
	a->next = NULL;
	return (a);
}

stack	*stack_init(int *array, int size)
{
	stack	*ba;
	stack	*ca;
	stack	*ea;
	int		i;

	if (size == 0 || array == NULL)
		return (NULL);
	i = 0;
	ca = NULL;
	ea = NULL;
	ba = create_stack(array[0]);
	if (!ba)
		return (NULL);
	ea = ba;
	while (array[i++] && i < size)
	{
		ca = create_stack(array[i]);
		if (i == 1)
			ba->next = ca;
		ca->previous = ea;
		ea->next = ca;
		ea = ca;
	}
	ba->previous = ea;
	return (ba);
}
