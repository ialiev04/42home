/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialiev <ialiev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:25:31 by ialiev            #+#    #+#             */
/*   Updated: 2024/11/14 21:04:47 by ialiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int tocheck)
{
	if ((tocheck > 64 && tocheck < 91) || (tocheck > 96 && tocheck < 123))
		return (1);
	else
		return (0);
}
