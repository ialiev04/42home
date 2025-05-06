/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialiev <ialiev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:50:31 by ialiev            #+#    #+#             */
/*   Updated: 2024/11/14 21:01:42 by ialiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*last_occurance;
	size_t		count_str;

	last_occurance = NULL;
	count_str = 0;
	while (str[count_str] != '\0')
	{
		if (str[count_str] == (char) c)
		{
			last_occurance = &str[count_str];
		}
		count_str++;
	}
	if ((char)c == '\0')
		return ((char *)&str[count_str]);
	if (last_occurance == NULL)
		return (NULL);
	return ((char *) last_occurance);
}
