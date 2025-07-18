/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:07:43 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/18 17:28:39 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ret;
	size_t			i;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (count != 0 && (SIZE_MAX / count) < size)
		return (NULL);
	ret = malloc(count * size);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < (count * size))
		((char *)ret)[i++] = 0;
	return (ret);
}
