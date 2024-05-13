/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:35:15 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/13 14:54:11 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int	size_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	t_stack_node	**a;
	t_stack_node	**b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	if (argc == 2)
		argv = split_and_check(argv);
	a = stack_init(argv, size_argv(argv));
	b = NULL;
	if (!is_sorted(*a))
	{
		if (pile_size(*a) == 2)
			sa(a);
		else if (pile_size(*a) == 3)
			sort_3(a);
		else
			ft_pushswap(a, b);
	}
	free_stack(a);
	return (0);
}
