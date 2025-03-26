/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialiev <ialiev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:08:40 by ialiev            #+#    #+#             */
/*   Updated: 2024/11/14 21:01:45 by ialiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*return_value;
	int		start;
	int		end;
	int		i;

	start = 0;
	end = ft_strlen(s1) - 1;
	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[start] != '\0' && ft_strchr(set, s1[start]) != NULL)
		start++;
	if (start > end)
		return (ft_strdup(""));
	while (end >= start && ft_strchr(set, s1[end]) != NULL)
		end--;
	return_value = (char *)malloc(end - start + 2);
	if (return_value == NULL)
		return (NULL);
	while (start <= end)
		return_value[i++] = s1[start++];
	return_value[i] = '\0';
	return (return_value);
}
