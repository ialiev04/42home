/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:52:56 by ilaliev           #+#    #+#             */
/*   Updated: 2025/03/11 12:57:00 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strchr(const char *s, int c)
{
	char	*ret;

	ret = (char *)s;
	while (*ret != '\0')
	{
		if (*ret == (char)c)
			return (ret);
		ret++;
	}
	if (c == '\0')
		return (ret);
	return (NULL);
}
