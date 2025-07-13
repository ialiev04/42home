/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:45:20 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/13 19:22:11 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	display_pixel_three(int i, t_pixel *p, t_fractol *f)
{
	if (i <= 110)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_22);
	else if (i <= 120)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_23);
	else if (i <= 130)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_1);
	else if (i <= 140)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_2);
	else if (i <= 150)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_3);
	else if (i <= 160)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_4);
	else if (i <= 170)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_5);
	else if (i <= 180)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_6);
	else if (i <= 200)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_7);
	else if (i <= 220)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_8);
	else if (i <= 250)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_9);
	else
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_10);
}

static void	display_pixel_two(int i, t_pixel *p, t_fractol *f)
{
	if (i <= 30)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_11);
	else if (i <= 32)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_12);
	else if (i <= 36)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_13);
	else if (i <= 40)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_14);
	else if (i <= 45)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_15);
	else if (i <= 50)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_16);
	else if (i <= 60)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_17);
	else if (i <= 70)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_18);
	else if (i <= 80)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_19);
	else if (i <= 90)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_20);
	else if (i <= 100)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_21);
	else
		display_pixel_three(i, p, f);
}

static void	display_pixel(int i, t_pixel *p, t_fractol *f)
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

void	calc_julia(t_pixel *pixel, t_fractol *fractol)
{
	double	zr;
	double	zi;
	double	zr2;
	double	zi2;
	int		i;

	zr = pixel->real_part;
	zi = pixel->imag_part;
	i = 0;
	while (i < pixel->max_iter)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if (zr2 + zi2 >= 4.0)
			break ;
		zi = 2 * zr * zi + pixel->julia_i;
		zr = zr2 - zi2 + pixel->julia_r;
		i++;
	}
	display_pixel(i, pixel, fractol);
}
