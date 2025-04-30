/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialiev <ialiev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:52:07 by ialiev            #+#    #+#             */
/*   Updated: 2024/11/14 21:03:40 by ialiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *tocount)
{
	int	count;

	count = 0;
	while (tocount[count] != '\0')
		count++;
	return (count);
}
