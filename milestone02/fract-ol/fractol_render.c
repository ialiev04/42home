/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:08:50 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/11 02:35:26 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void	find_and_display(int x, int y, t_pixel *pxl, t_fractol *fractol)
{
	pxl->real_part = pxl->min_cd_r + x * (pxl->max_cd_r - pxl->min_cd_r) / WIDTH;
	pxl->imag_part = pxl->min_cd_i + y * (pxl->max_cd_i  - pxl->min_cd_i) / HEIGHT;
	pxl->real_coord = x;
	pxl->imag_coord = y;
	if (!ft_strncmp(fractol->name, "mandelbrot", 10))
		calc_mandel(pxl, fractol);
	// else if (!ft_strncmp(fractol->name, "julia", 5))
	// 	display_julia(pxl);
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
	mlx_image_to_window(fractol->mlx, fractol->img, 0, 0);
}
