/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:14:32 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/13 14:44:36 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int	*convert_in_int_array(char **argv)
{
	int	i;
	int	*int_array;

	i = 1;
	if (!argv[i])
		return (NULL);
	while (argv[i])
		i++;
	int_array = malloc((i + 1) * sizeof(int));
	if (!int_array)
		return (NULL);
	i = 0;
	while (argv[i])
	{
		int_array[i] = ft_atoi(argv[i]);
		i++;
	}
	if (ft_check_error_int_array(int_array) == 0)
	{
		free (int_array);
		return (NULL);
	}
	return (int_array);
}

static t_stack_node	*create_node(int n)
{
	t_stack_node	*a;

	a = malloc(sizeof(t_stack_node));
	if (!a)
		return (NULL);
	a->data = n;
	a->previous = NULL;
	a->next = NULL;
	a->price = 0;
	a->target = NULL;
	a->cheapest = false;
	a->under_avg_rank = false;
	a->index = 0;
	return (a);
}

t_stack_node	**stack_init(char **argv, int size)
{
	t_stack_node	**ba;
	t_stack_node	**ca;
	t_stack_node	**ea;
	int				i;
	int				*int_array;

	int_array = convert_in_int_array(argv);
	if (size == 0 || argv[1] == NULL || int_array == NULL)
		return (NULL);
	i = 0;
	ca = NULL;
	ba = NULL;
	ea = NULL;
	*ba = create_node(int_array[0]);
	*ea = *ba;
	while (int_array[i++] && i < size)
	{
		*ca = create_node(int_array[i]);
		if (i == 1)
			(*ba)->next = *ca;
		(*ca)->previous = *ea;
		(*ea)->next = *ca;
		(*ea) = *ca;
	}
	return (ba);
}
