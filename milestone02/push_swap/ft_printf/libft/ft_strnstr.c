/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialiev <ialiev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:16:50 by ialiev            #+#    #+#             */
/*   Updated: 2024/11/14 21:19:40 by ialiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	ndl_len;
	size_t	ct_hay;
	size_t	chk_ndl;

	ndl_len = 0;
	ct_hay = 0;
	chk_ndl = 0;
	while (needle[ndl_len] != '\0')
		ndl_len++;
	if (ndl_len == 0)
		return ((char *)haystack);
	while (haystack[ct_hay] != '\0' && ct_hay + ndl_len <= len)
	{
		while (haystack[ct_hay + chk_ndl] == needle[chk_ndl]
			&& (ct_hay + chk_ndl) < len)
		{
			chk_ndl++;
			if (needle[chk_ndl] == '\0')
				return ((char *)&haystack[ct_hay]);
		}
		chk_ndl = 0;
		ct_hay++;
	}
	return (NULL);
}
