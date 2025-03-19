/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:02:49 by ilaliev           #+#    #+#             */
/*   Updated: 2025/03/18 20:02:49 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(int c)
{
	int	i;

	i = write(1, &c, 1);
	return (i)
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	if (s == NULL)
		s = "(null)";
	while (s[i])
		if (write(1, &s[i++], 1) == -1)
			return (-1)
	return (i);
}

int	print_adr(uintptr_t p)
{
	int	len;

	if (write(1, "0x", 1) < 0)
		return (-1);
	if (p == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		return (3);
	}
	else
	{
		if (put_hex < 0)
			return (-1);
		len += hex_len(p); //todo
	}
	return (len);
}
