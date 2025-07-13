/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:08:50 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/13 18:22:47 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	find_and_display(int x, int y, t_pixel *p, t_fractol *fractol)
{
	p->real_part = p->min_cd_r + x * (p->max_cd_r - p->min_cd_r) / WIDTH;
	p->imag_part = p->max_cd_i - y * (p->max_cd_i - p->min_cd_i) / HEIGHT;
	p->real_coord = x;
	p->imag_coord = y;
	if (!ft_strncmp(fractol->name, "mandelbrot", 10))
		calc_mandel(p, fractol);
	else if (!ft_strncmp(fractol->name, "julia", 5))
		calc_julia(p, fractol);
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
