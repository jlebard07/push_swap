/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:55:34 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/28 14:55:34 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./includes/push_swap.h"

bool	check_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] != '-'
				|| (str[i] == '-' && i != 0)
				|| (str[i] == '-' && str[i + 1] == 0))
			&& (str[i] != '+'
				|| (str[i] == '+' && i != 0)
				|| (str[i] == '+' && str[i + 1] == 0)))
			return (false);
		i++;
	}
	return (true);
}

bool	check_rep(t_stack_node *stack, int n)
{
	while (stack)
	{
		if (stack->value == n)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;

	if (!*stack || !stack)
		return ;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	*stack = NULL;
}

void	free_argv(char **argv)
{
	int	i;

	if (!argv ||!argv[0][0])
		return ;
	i = 0;
	while (argv[i])
		i++;
	while (i >= 0)
		free(argv[i--]);
	free(argv);
}

void	error_free(t_stack_node **stack, char **argv, bool nb_argc)
{
	free_stack(stack);
	if (nb_argc)
		free_argv(argv);
	write(2, "Error\n", 6);
	exit (1);
}
