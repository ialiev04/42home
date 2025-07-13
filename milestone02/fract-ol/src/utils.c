/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:51:12 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/13 21:05:01 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	clean_exit(t_fractol *fractol, int error)
{
	if (error == 1)
		error_msg();
	if (fractol->img)
		mlx_delete_image(fractol->mlx, fractol->img);
	if (fractol->mlx)
		mlx_terminate(fractol->mlx);
	free(fractol->pixel);
	free(fractol);
	exit(0);
}

int	error_msg(void)
{
	ft_printf("**********************************************************\n");
	ft_printf("INVALID INPUT!\n\n");
	ft_printf("For Mandelbrot please enter:	./fractol mandelbrot\n");
	ft_printf("For Julia please enter:		./fractol julia -0.36 0.6\n");
	ft_printf("Possible julias you can try:\n");
	ft_printf("-0.76 0.3\n");
	ft_printf("-1.75 -0.01\n");
	ft_printf("0.4 -0.2\n");
	ft_printf("**********************************************************\n");
	return (1);
}
