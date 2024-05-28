/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:56:25 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/28 14:56:25 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	else if (argv[1][0] == '\0')
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, argv + 1, argc == 2);
	if (!is_sorted(a))
	{
		if (pile_size(a) == 2)
			sa(&a);
		else if (pile_size(a) == 3)
			sort_3(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}
