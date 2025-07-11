/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_mandel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:45:20 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/11 16:45:13 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"
void	display_pixel_two(int i, t_pixel *p, t_fractol *f)
{
	if (i <= 32)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_12);
	else if (i <= 36)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_13);
	else if (i <= 40)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_14);
	else if (i <= 45)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_15);
	else if (i <= 50)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_16);
	else if (i <= 55)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_17);
	else if (i <= 60)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_18);
	else if (i <= 70)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_19);
	else if (i <= 80)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_20);
	else if (i <= 90)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_21);
	else if (i <= 100)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_22);
	else
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_23);
}

void	display_pixel(int i, t_pixel *p, t_fractol *f)
{
	if (i == p->max_iter)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_BLACK);
	else if (i <= 2)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_1);
	else if (i <= 4)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_2);
	else if (i <= 6)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_3);
	else if (i <= 8)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_4);
	else if (i <= 10)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_5);
	else if (i <= 12)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_6);
	else if (i <= 16)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_7);
	else if (i <= 20)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_8);
	else if (i <= 24)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_9);
	else if (i <= 28)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_10);
	else if (i <= 30)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_11);
	else
		display_pixel_two(i, p, f);
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
	while (i < pixel->max_iter)
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
