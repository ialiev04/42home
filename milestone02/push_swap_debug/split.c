/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:25:48 by ilaliev           #+#    #+#             */
/*   Updated: 2025/05/22 19:12:54 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_wordct(char *s, char c)
{
	int	ct;
	int	in_word;

	ct = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			ct++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (ct);
}

static int	ft_word_len(char *s, char c, int j)
{
	int	i;

	i = 0;
	while (s[j + i] != c && s[j + i] != '\0')
		i++;
	return (i);
}

static char	*ft_fillword(char *s, char c, int j)
{
	char	*ret;
	int		i;
	int		word_len;

	i = 0;
	word_len = ft_word_len(s, c, j);
	ret = ft_calloc(word_len + 1, sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (i < word_len)
		ret[i++] = s[j++];
	ret[i] = '\0';
	return (ret);
}

static void	*ft_free_split(char **ret, unsigned int how_many)
{
	unsigned int	i;

	i = 0;
	while (i < how_many)
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	exit (1);
}

char	**split(char *s, char c)
{
	char			**ret;
	unsigned int	words;
	unsigned int	i;
	unsigned int	j;

	words = ft_wordct(s, c);
	if (words < 1)
		exit(0);
	ret = ft_calloc(words + 1, sizeof(char *));
	if (ret == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < words)
	{
		while (s[j] == c)
			j++;
		ret[i] = ft_fillword((char *)s, c, j);
		if (ret[i] == NULL)
			(ft_free_split(ret, i));
		j = j + ft_word_len((char *)s, c, j);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
