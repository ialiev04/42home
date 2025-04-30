/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialiev <ialiev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:09:02 by ialiev            #+#    #+#             */
/*   Updated: 2024/11/14 21:03:30 by ialiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	value;
	unsigned char	*dst;
	size_t			i;

	value = (unsigned char) c;
	dst = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		dst[i] = value;
		i++;
	}
	return (b);
}
