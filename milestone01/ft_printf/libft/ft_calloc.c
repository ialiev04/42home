/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialiev <ialiev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:44:29 by ialiev            #+#    #+#             */
/*   Updated: 2024/11/14 21:05:17 by ialiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*return_val;
	size_t	i;

	i = 0;
	if (count == 0 || size == 0)
		return (malloc(0));
	if (count != 0 && (SIZE_MAX / count) < size)
		return (NULL);
	total_size = count * size;
	return_val = malloc(total_size);
	if (return_val == NULL)
		return (NULL);
	while (i < total_size)
	{
		((char *)return_val)[i] = 0;
		i++;
	}
	return (return_val);
}
