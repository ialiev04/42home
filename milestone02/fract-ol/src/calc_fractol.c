/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:45:20 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/17 17:53:42 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static uint32_t	get_color(int i, t_pixel *p)
{
	double		t;
	uint32_t	color;
	
	t = (double)i / 20;
	color = 0;
	if (p->color_palette == 0)
	{
		color |= (uint8_t)((sin(t * 10.0) * 0.5 + 0.5) * 255) << 24;
		color |= (uint8_t)((sin(t * 7.0 + 2.0) * 0.5 + 0.5) * 255) << 16;
		color |= (uint8_t)((sin(t * 13.0 + 5.0) * 0.5 + 0.5) * 255) << 8;
	}
	else if (p->color_palette == 1)
	{
		color |= (uint8_t)(sqrt(t) * 255) << 24;
		color |= (uint8_t)(sqrt(t) * 255) << 16;
		color |= (uint8_t)(sqrt(t) * 255) << 8;
	}
	else if (p->color_palette == 2)
	{
		t = (double)i / p->max_iter;
		color |= (uint8_t)(sin(t * 1.5) * 120 + 10) << 24;
		color |= (uint8_t)(sin(t * 1.5) * 50 + 5) << 16;
		color |= (uint8_t)(sin(t * 1.5) * 130 + 15) << 8;
	}
	return (color | 255);
}

static void	display_pixel(int i, t_pixel *p, t_fractol *f)
{
	uint32_t	color;

	if (i == p->max_iter)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_BLACK);
	else
	{
		color = get_color(i, p);
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, color);
	}
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

void	calc_multi(t_pixel *pixel, t_fractol *fractol)
{
	double	zr;
	double	zi;
	double	zr2;
	double	zi2;
	double	tmp_zr;
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
		tmp_zr = zr * zr * zr - 3 * zr * zi * zi + pixel->real_part;
		zi = 3 * zr * zr * zi - zi * zi * zi + pixel->imag_part;
		zr = tmp_zr;
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
