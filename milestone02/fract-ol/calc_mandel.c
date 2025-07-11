/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_mandel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:45:20 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/11 04:39:26 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void	display_pixel(int i, t_pixel *p, t_fractol *f)
{
	if (i == MAX_ITER)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_BLACK);
	else if (i <= 5)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_2);
	else if (i <= 10)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_3);
	else if (i <= 15)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_4);
	else if (i <= 25)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_5);
	else if (i <= 40)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_6);
	else if (i <= 45)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_7);
	else if (i <= 50)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_8);
	else if (1 <= 55)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_9);
	else if (1 <= 60)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_10);
	else if (1 <= 65)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_11);
	else if (1 <= 70)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_12);
	else if (1 <= 75)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_13);
}

void	calc_mandel(t_pixel *pixel, t_fractol *fractol)
{
	double	zr;
	double	zi;
	double	zr2;
	double	zi2;
	int		i;

	zr = 0;
	zi = 0;
	i = 0;
	while (i < MAX_ITER)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if (zr2 + zi2 >= 4)
			break ;
		zi = 2 * zr * zi + pixel->imag_part;
		zr = zr2 - zi2 + pixel->real_part;
		i++;
	}
	display_pixel(i, pixel, fractol);
}
