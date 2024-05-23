/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:48:53 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/13 13:57:51 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	ft_free_memory(char **dest)
{
	int	i;

	i = 0;
	while (dest[i] != 0)
	{
		free(dest[i]);
		i++;
	}
	free (dest);
}

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	compteur;

	i = 0;
	compteur = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i])
		{
			if ((s[i] == c && s[i + 1] != c) || (s[i + 1] == '\0'))
				compteur ++;
			i++;
		}
	}
	return (compteur);
}

static char	*ft_write_word(char const *s, char	*dest, char c)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_write_split(char **dest, char const *s, char c)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		j = 0;
		if (s[i] == c)
			i++;
		else
		{
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			dest[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!dest[word])
				return (-1);
			ft_write_word(s + i, dest[word], c);
			i += j;
			word++;
		}
	}
	return (0);
}

char	**ft_split(char *s, char c)
{
	int		words;
	char	**dest;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	dest = (char **)malloc(sizeof(char *) * (words + 1));
	if (!dest)
		return (NULL);
	dest[words] = NULL;
	if (ft_write_split(dest, s, c) == -1)
	{
		ft_free_memory(dest);
		return (NULL);
	}
	return (dest);
}
