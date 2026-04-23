/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 05:22:20 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/18 16:42:13 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;
	char	*last_ret;

	ret = (char *)s;
	last_ret = NULL;
	while (*ret != '\0')
	{
		if (*ret == (char)c)
			last_ret = ret;
		ret++;
	}
	if ((char)c == '\0')
		return (ret);
	return (last_ret);
}
