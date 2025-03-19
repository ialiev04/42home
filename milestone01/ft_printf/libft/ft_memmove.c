/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:02:52 by ilaliev           #+#    #+#             */
/*   Updated: 2025/03/10 18:26:53 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*sauce;
	size_t			i;

	if (!src && !dst)
		return (NULL);
	dest = (unsigned char *) dst;
	sauce = (unsigned char *) src;
	if (dst > src)
	{
		while (len-- > 0)
			dest[len] = sauce[len];
	}
	else
	{
		while (i++ < len)
			dest[i] = sauce[i];
	}
	return (dst);
}
