/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 22:06:51 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/18 16:42:18 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	sub_len;
	size_t	i;

	if (!s)
		return (NULL);
	sub_len = ft_strlen(s);
	if (start >= sub_len)
		return (ft_strdup(""));
	sub_len = sub_len - start;
	if (sub_len > len)
		sub_len = len;
	ret = malloc(sub_len + 1);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < sub_len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
