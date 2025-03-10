/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:34:01 by ilaliev           #+#    #+#             */
/*   Updated: 2025/03/10 18:19:08 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*sauce;

	if (!src && !dst)
		return (NULL);
	dest = (unsigned char *) dst;
	sauce = (unsigned char *) src;
	while (n > 0)
	{
		*dest++ = *sauce++;
		n--;
	}
	return (dst);
}
