/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:13:37 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/13 14:15:26 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_atoi(const char	*str)
{
	char	*temp;
	int		i;
	int		n;
	int		j;

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
