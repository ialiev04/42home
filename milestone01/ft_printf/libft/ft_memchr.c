/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialiev <ialiev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:48:55 by ialiev            #+#    #+#             */
/*   Updated: 2024/11/14 21:03:28 by ialiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	to_find;
	unsigned char	*string;
	size_t			i;

	to_find = (unsigned char) c;
	string = (unsigned char *) s;
	i = 0;
	while (i < n && string[i] != to_find)
		i++;
	if (i == n)
		return (NULL);
	else
		return ((void *)(string + i));
}
