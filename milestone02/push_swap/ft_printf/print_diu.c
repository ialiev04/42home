/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:08:38 by ilaliev           #+#    #+#             */
/*   Updated: 2025/05/13 17:19:47 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static char	*ft_itoa(int n)
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

int	print_sint(int num)
{
	char	*num_ascii;
	int		i;

	num_ascii = ft_itoa(num);
	if (!num_ascii)
		return (-1);
	i = 0;
	while (num_ascii[i])
	{
		if (write(1, &num_ascii[i], 1) < 1)
		{
			free(num_ascii);
			return (-1);
		}
		i++;
	}
	free(num_ascii);
	return (i);
}

int	print_uint(int num)
{
	char	*num_ascii;
	int		i;

	num_ascii = ft_uitoa(num);
	if (!num_ascii)
		return (-1);
	i = 0;
	while (num_ascii[i])
	{
		if (write(1, &num_ascii[i++], 1) < 1)
		{
			free(num_ascii);
			return (-1);
		}
	}
	free(num_ascii);
	return (i);
}
