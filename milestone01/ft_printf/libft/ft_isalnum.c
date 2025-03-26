/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialiev <ialiev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:16:28 by ialiev            #+#    #+#             */
/*   Updated: 2024/11/14 21:05:06 by ialiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int tocheck)
{
	if ((tocheck > 64 && tocheck < 91) || (tocheck > 96 && tocheck < 123))
		return (1);
	else if (tocheck > 47 && tocheck < 58)
		return (1);
	else
		return (0);
}
