/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:45:38 by ilaliev           #+#    #+#             */
/*   Updated: 2025/03/20 13:30:16 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(int n)
{
	int		len;
	long	num;

	if (n >= 0 && n <= 9)
		return (1);
	len = 0;
	num = (long)n;
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	num;
	char	*ret;

	len = ft_num_len(n);
	num = (long)n;
	if (num < 0)
		num = -num;
	ret = malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	ret[len] = '\0';
	while (len > 0)
	{
		ret[--len] = (num % 10) + '0';
		num = num / 10;
	}
	if (n < 0)
		ret[0] = '-';
	return (ret);
}
