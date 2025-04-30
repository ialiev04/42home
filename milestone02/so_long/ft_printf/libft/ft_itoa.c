/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialiev <ialiev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:02:51 by ialiev            #+#    #+#             */
/*   Updated: 2024/11/15 23:00:26 by ialiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_length(int n)
{
	int		length;
	long	num;

	num = (long)n;
	length = 0;
	if (num <= 9 && num >= 0)
		return (1);
	if (num < 0)
	{
		length++;
		num = -num;
	}
	while (num != 0)
	{
		num = num / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	int		length;
	char	*return_val;
	long	num;

	length = ft_num_length(n);
	num = (long)n;
	return_val = (char *)malloc(length + 1);
	if (return_val == NULL)
		return (NULL);
	return_val[length] = '\0';
	if (num < 0)
		num = -num;
	while (length > 0 && return_val[length] != '-')
	{
		return_val[--length] = (num % 10) + '0';
		num = num / 10;
	}
	if (n < 0)
		return_val[0] = '-';
	return (return_val);
}

// int	main()
// {
// 	char	*test;

// 	test = ft_itoa();
// 	printf("Converted number: %s\n", test);
// 	return (0);
// }