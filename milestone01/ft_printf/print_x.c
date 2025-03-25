/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:32:34 by ilaliev           #+#    #+#             */
/*   Updated: 2025/03/25 18:18:40 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int x, char format)
{
	if (x == 0)
		return (write(1, "0", 1));
	else if (put_hex(x, format) < 0)
		return (-1);
	return (hex_len(x));
}
