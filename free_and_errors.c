/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:12:22 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/13 14:11:54 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*current;

	current = *stack;
	while (current)
	{
		temp = current->next;
		free (current);
		current = temp;
	}	
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

bool	ft_check_error_int_array(int *int_arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (int_arr[i])
		i++;
	while (i >= 0)
	{
		while (int_arr[j])
		{
			if (int_arr[j] == int_arr[i])
			{
				ft_write_error();
				return (false);
			}
			j++;
		}
		i--;
		j = 0;
	}
	return (true);
}

void	ft_write_error(void)
{
	char	*error;

	error = "Error\n";
	ft_putstr_fd(error, 2);
}
