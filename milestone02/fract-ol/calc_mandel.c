/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_mandel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:45:20 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/10 16:14:02 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void	display_pixel(int i, t_pixel *p, t_fractol *f)
{
	if (i == MAX_ITER)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_BLACK);
	else if (i <= 10)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_RED);
	else if (i <= 20)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_PURPLE);
	else if (i <= 40)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_PINK);
	else if (i <= 60)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_ORANGE);
	else if (i <= 80)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_MAGENTA);
	else if (i <= 100)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_LIME);
	else if (i <= 200)
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_GREEN);
	else
		mlx_put_pixel(f->img, p->real_coord, p->imag_coord, COLOR_BLUE);
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
int32_t	main(void)
{
	t_fractol	fractol;
	t_pixel		pixel;

	fractol.mlx = mlx_init(WIDTH, HEIGHT, "Mandelbrot Viewer", false);
	if (!fractol.mlx)
		return (EXIT_FAILURE);
	fractol.img = mlx_new_image(fractol.mlx, WIDTH, HEIGHT);
	if (!fractol.img)
		return (EXIT_FAILURE);
	fractol.pixel = &pixel;
	fractol.name = "mandelbrot";
	fractol_render(&fractol);
	mlx_image_to_window(fractol.mlx, fractol.img, 0, 0);
	mlx_loop(fractol.mlx);
	mlx_terminate(fractol.mlx);
	return (EXIT_SUCCESS);
}