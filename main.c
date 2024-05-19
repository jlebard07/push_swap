/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:35:15 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/16 17:09:15 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	else if (argc == 2)
	{
		if (ft_check_error_str(argv[1]) == 0)
			return (1);
		argv = ft_split(argv[1], ' ');
	}
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
	free_stack(&a);
	return (0);
}
