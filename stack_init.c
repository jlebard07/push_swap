/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:03:10 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/28 15:03:10 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static long long int	ft_atoi(char *str)
{
	char			*temp;
	int				i;
	int				n;
	long long int	j;

	temp = (char *)str;
	i = 0;
	n = 0;
	j = 0;
	while ((temp[i] > 8 && temp[i] < 14) || (temp[i] == 32))
		i++;
	if (temp[i] == 43 || temp[i] == 45)
	{
		if (temp[i] == 45)
			n++;
		i++;
	}
	while (temp[i] > 47 && temp[i] < 58)
	{
		j = j * 10 + (temp[i] - 48);
		i++;
	}
	if (n == 1)
		return (-j);
	return (j);
}

static void	create_node(t_stack_node **stack, int n)
{
	t_stack_node	*temp;
	t_stack_node	*last;

	if (!stack)
		return ;
	temp = malloc(sizeof(t_stack_node));
	if (!temp)
		return ;
	temp->next = NULL;
	temp->value = n;
	if (stack && !*stack)
	{	
		temp->previous = NULL;
		*stack = temp;
	}
	else if (*stack)
	{
		last = find_last(*stack);
		last->next = temp;
		temp->previous = last;
	}
}

void	stack_init(t_stack_node **stack, char **argv,
					bool nb_argc)
{
	int				i;
	long long int	n;

	i = 0;
	if (nb_argc)
		argv = argv - 1;
	while (argv[i])
	{
		if (!(check_str(argv[i])))
			error_free(stack, argv, nb_argc);
		n = ft_atoi(argv[i]);
		if (n < INT_MIN || n > INT_MAX)
			error_free(stack, argv, nb_argc);
		if (!(check_rep(*stack, (int)n)))
			error_free(stack, argv, nb_argc);
		create_node(stack, n);
		i++;
	}
	if (nb_argc)
		free_argv(argv);
}
