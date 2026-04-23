/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:00:12 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/18 16:42:15 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		start;
	int		end;
	int		i;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	if (start > end)
		return (ft_strdup(""));
	while (end >= start && ft_strchr(set, s1[end]))
		end--;
	ret = malloc(end - start + 2);
	if (!ret)
		return (NULL);
	i = 0;
	while (start <= end)
		ret[i++] = s1[start++];
	ret[i] = '\0';
	return (ret);
}
