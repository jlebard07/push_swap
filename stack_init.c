/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:40:06 by jlebard           #+#    #+#             */
/*   Updated: 2024/04/03 11:39:36 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	*convert_in_int_array(char **str_arr)
{
	int	i;
	int	*int_array;

	i = 0;
	while (str_arr[i])
		i++;
	int_array = malloc((i + 1) * sizeof(int));
	if (!int_array)
		return (NULL);
	i = 0;
	while (str_arr[i])
	{
		int_array[i] = ft_atoi(str_arr[i]);
		i++;
	}
	return (int_array);
}

static int	*split_and_check(char	*str)
{
	char	**temp;
	int		i;
	int		*int_array;

	i = 0;
	if (!ft_check_error_str(str))
		return (NULL);
	temp = ft_split(str, ' ');
	int_array = convert_in_int_array(temp);
	free(temp);
	if (ft_check_error_int_array(int_array) == false)
		return (NULL);
	return (int_array);
}

stack	stack_init(char	*str)
{
	char	**temp;
	stack	ba;
	stack	ea;

	temp = split_and_check(str);
}
