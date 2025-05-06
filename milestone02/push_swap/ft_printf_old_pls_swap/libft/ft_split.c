/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialiev <ialiev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:13:25 by ialiev            #+#    #+#             */
/*   Updated: 2024/11/16 05:41:40 by ialiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_split(char **array, unsigned int words_allocated)
{
	unsigned int	i;

	i = 0;
	while (i < words_allocated)
		free(array[i++]);
	free(array);
	return (0);
}

static unsigned int	count_words(char const *s, char c)
{
	int				i;
	int				in_word;
	unsigned int	count;

	i = 0;
	in_word = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static int	word_length(const char *s, char c)
{
	int	length;

	length = 0;
	while (s[length] != c && s[length] != '\0')
		length++;
	return (length);
}

static char	*save_word(const char *s, int len)
{
	char	*word;
	int		j;

	j = 0;
	word = (char *)malloc(len + 1);
	if (word == NULL)
		return (NULL);
	while (j < len)
	{
		word[j] = s[j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char			**result;
	unsigned int	words;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	words = count_words(s, c);
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (i < words)
	{
		while (s[j] == c)
			j++;
		result[i] = save_word(&s[j], word_length(&s[j], c));
		if (!result[i])
			return (free_split(result, i));
		j = j + word_length(&s[j], c);
		i++;
	}
	result[i] = NULL;
	return (result);
}
