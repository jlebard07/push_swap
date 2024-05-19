/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:12:22 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/16 16:37:10 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	free_argv(char	**argv)
{
	int	i;

	i = 0;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
		free(argv[i++]);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*current;

	if (*stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free (current);
		current = temp;
	}
	*stack = NULL;
}

void	free_error(t_stack_node **stack, char **argv, bool n_argc)
{
	free_stack(stack);
	if (n_argc == true)
		free_argv(argv);
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

bool	ft_check_error_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57 || str[i] != 32)
		{
			ft_putstr_fd("Error\n", 2);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	ft_check_error_repetition(t_stack_node *stack, int n)
{
	if (stack == NULL)
		return (true);
	while (stack)
	{
		if (n == stack->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}
