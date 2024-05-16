/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:14:32 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/16 16:37:54 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static	void	create_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->data = n;
	node->next = NULL;
	if (*stack == NULL)
	{
		node->previous = NULL;
		*stack = node;
	}
	else
	{
		last = find_last(*stack);
		last->next = node;
		node->previous = last;
	}
}

void	stack_init(t_stack_node **a, char **argv)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		nbr = (long)ft_atoi(argv[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
		{
			free_argv(argv);
			free_stack(a);
			ft_write_error();
		}
		if (ft_check_error_repetition(*a, (int)nbr) == 0)
		{
			free_argv(argv);
			free_stack(a);
		}
		create_node(a, (int)nbr);
		i++;
	}
}
