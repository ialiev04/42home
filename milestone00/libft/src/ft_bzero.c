/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:26:33 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/18 16:38:02 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset (s, 0, n);
	return ;
}
// {
// 	unsigned char	*str;

// 	str = (unsigned char *)s;
// 	while (n > 0)
// 	{
// 		*str++ = 0;
// 		n--;
// 	}
// 	return ;
// }
