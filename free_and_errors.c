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
	free(argv - 1);
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

bool	ft_check_error_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57 || str[i] != 32)
		{
			ft_write_error();
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
		{
			return (false);
			ft_write_error();
		}
		stack = stack->next;
	}
	return (true);
}

void	ft_write_error(void)
{
	char	*error;

	error = "Error\n";
	ft_putstr_fd(error, 2);
}
