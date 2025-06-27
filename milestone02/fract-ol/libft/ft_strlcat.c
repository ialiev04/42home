/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 02:01:26 by ilaliev           #+#    #+#             */
/*   Updated: 2025/03/20 14:07:03 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	space_left;
	size_t	i;

	dstlen = ft_strlen((const char *)dst);
	srclen = ft_strlen((const char *)src);
	space_left = dstsize - dstlen - 1;
	i = 0;
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	while (i < space_left && src[i])
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
