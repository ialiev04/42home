/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialiev <ialiev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:00:50 by ialiev            #+#    #+#             */
/*   Updated: 2024/11/14 20:59:02 by ialiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	is_pos;
	int	return_val;

	i = 0;
	is_pos = 1;
	return_val = 0;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-')
	{
		is_pos = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] == '0')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		return_val = return_val * 10 + (s[i] - '0');
		i++;
	}
	return_val = return_val * is_pos;
	return (return_val);
}
