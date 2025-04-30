/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialiev <ialiev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:08:33 by ialiev            #+#    #+#             */
/*   Updated: 2024/11/14 21:03:37 by ialiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	left_spc;
	size_t	i;

	len_dst = 0;
	len_src = 0;
	while (dst[len_dst] != '\0' && len_dst < dstsize)
		len_dst++;
	while (src[len_src] != '\0')
		len_src++;
	if (dstsize <= len_dst)
		return (len_dst + len_src);
	left_spc = dstsize - 1 - len_dst;
	i = 0;
	while (i < left_spc && src[i] != '\0')
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
