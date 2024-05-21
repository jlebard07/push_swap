/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:35:15 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/21 12:14:48 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	print_stack(t_stack_node *a)
{
	while (a)
	{
		printf("%d, ", a->data);
		a = a->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
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
			ft_pushswap(&a, &b);
	}
	print_stack(a);
	free_stack(&a);
	return (0);
}
