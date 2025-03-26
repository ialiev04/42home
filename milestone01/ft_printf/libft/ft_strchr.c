/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialiev <ialiev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:12:07 by ialiev            #+#    #+#             */
/*   Updated: 2024/11/16 02:27:05 by ialiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
