/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialiev <ialiev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:34:42 by ialiev            #+#    #+#             */
/*   Updated: 2024/11/14 21:03:37 by ialiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
