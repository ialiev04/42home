/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:08:50 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/10 16:03:13 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void	find_and_display(int x, int y, t_pixel *pixel, t_fractol *fractol)
{
	pixel->real_part = MIN_REAL + x * (MAX_REAL - MIN_REAL) / WIDTH;
	pixel->imag_part = MIN_IMAG + y * (MAX_IMAG - MIN_IMAG) / HEIGHT;
	pixel->real_coord = x;
	pixel->imag_coord = y;
	if (!ft_strncmp(fractol->name, "mandelbrot", 10))
		calc_mandel(pixel, fractol);
	// else if (!ft_strncmp(fractol->name, "julia", 5))
	// 	display_julia(pixel);
}

void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			find_and_display(x, y, fractol->pixel, fractol);
			y++;
		}
		x++;
	}
}
