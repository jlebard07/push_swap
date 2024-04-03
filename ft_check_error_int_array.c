/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error_int_array.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:29:41 by jlebard           #+#    #+#             */
/*   Updated: 2024/04/03 11:37:58 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
