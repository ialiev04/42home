/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:17:59 by ilaliev           #+#    #+#             */
/*   Updated: 2025/03/19 17:17:59 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	count_str;
	char	*ret_str;
	char	to_find;

	ret_str = (char *)str;
	count_str = 0;
	to_find = (char)c;
	while (ret_str[count_str] != '\0')
	{
		if (ret_str[count_str] == to_find)
			return (&ret_str[count_str]);
		count_str++;
	}
	if (to_find == '\0')
		return (&ret_str[count_str]);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	size_t	i;
	char	*copy;

	s1_len = 0;
	i = 0;
	while (s1[s1_len] != '\0')
		s1_len++;
	copy = malloc(s1_len + 1);
	if (copy == NULL)
		return (NULL);
	while (i < s1_len)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

unsigned int	ft_strlen(const char *tocount)
{
	int	count;

	count = 0;
	while (tocount[count] != '\0')
		count++;
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	counter;
	size_t	i;

	if (len == 0)
		return (ft_strdup(""));
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	counter = start;
	i = 0;
	while (counter < len + start)
	{
		substr[i] = s[counter];
		counter++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*return_val;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	return_val = (char *)malloc(s1_len + s2_len + 1);
	if (return_val == NULL)
		return (NULL);
	while (i < s1_len)
	{
		return_val[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		return_val[s1_len + i] = s2[i];
		i++;
	}
	return_val[s1_len + s2_len] = '\0';
	return (return_val);
}
