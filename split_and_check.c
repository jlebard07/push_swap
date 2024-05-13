/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_and_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:40:06 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/13 14:43:03 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

char	**split_and_check(char **argv)
{
	char	**temp;
	int		i;

	temp = NULL;
	i = 0;
	if (ft_check_error_str(argv[1]) == 0)
		return (NULL);
	temp = ft_split(argv[1], ' ');
	argv = temp;
	free(temp);
	return (argv);
}
