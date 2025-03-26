/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialiev <ialiev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:35:27 by ialiev            #+#    #+#             */
/*   Updated: 2024/11/14 21:27:08 by ialiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*return_val;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
		i++;
	return_val = (char *)malloc((size_t)i + 1);
	if (return_val == NULL)
		return (NULL);
	return_val[i] = '\0';
	while (i > 0)
	{
		i--;
		return_val[i] = (*f)(i, s[i]);
	}
	return (return_val);
}
