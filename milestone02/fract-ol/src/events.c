/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 01:57:22 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/13 18:57:14 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	handle_movement_keys(mlx_key_data_t event, t_fractol *fractol)
{
	double	step_x;
	double	step_y;

	step_x = (fractol->pixel->max_cd_r - fractol->pixel->min_cd_r) * 0.1;
	step_y = (fractol->pixel->max_cd_i - fractol->pixel->min_cd_i) * 0.1;
	if (event.key == MLX_KEY_LEFT)
	{
		fractol->pixel->max_cd_r -= step_x;
		fractol->pixel->min_cd_r -= step_x;
	}
	else if (event.key == MLX_KEY_RIGHT)
	{
		fractol->pixel->max_cd_r += step_x;
		fractol->pixel->min_cd_r += step_x;
	}
	else if (event.key == MLX_KEY_DOWN)
	{
		fractol->pixel->max_cd_i -= step_y;
		fractol->pixel->min_cd_i -= step_y;
	}
	else if (event.key == MLX_KEY_UP)
	{
		fractol->pixel->max_cd_i += step_y;
		fractol->pixel->min_cd_i += step_y;
	}
}

void	my_key(mlx_key_data_t event, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (event.action != MLX_PRESS)
		return ;
	if (event.key == MLX_KEY_ESCAPE)
		clean_exit(fractol, 0);
	else if (event.key == MLX_KEY_M || event.key == MLX_KEY_P)
	{
		if (event.key == MLX_KEY_M)
			fractol->pixel->max_iter *= 0.7;
		else
			fractol->pixel->max_iter *= 1.5;
		if (fractol->pixel->max_iter < 2)
			fractol->pixel->max_iter = 2;
		fractol_render(fractol);
	}
	else
	{
		handle_movement_keys(event, fractol);
		fractol_render(fractol);
	}
}

static void	calc_zoom(t_fractol *f, int ms_x, int ms_y, double zoom_factor)
{
	double	width;
	double	height;
	double	mouse_r;
	double	mouse_i;
	t_pixel	*p;

	p = f->pixel;
	width = p->max_cd_r - p->min_cd_r;
	height = p->max_cd_i - p->min_cd_i;
	mouse_r = p->min_cd_r + ((double)ms_x / WIDTH) * width;
	mouse_i = p->min_cd_i + ((double)(HEIGHT - ms_y) / HEIGHT) * height;
	width *= zoom_factor;
	height *= zoom_factor;
	p->min_cd_r = mouse_r - ((double)ms_x / WIDTH) * width;
	p->max_cd_r = p->min_cd_r + width;
	p->min_cd_i = mouse_i - ((double)(HEIGHT - ms_y) / HEIGHT) * height;
	p->max_cd_i = p->min_cd_i + height;
}

void	my_scroll(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;
	int			mouse_x;
	int			mouse_y;
	double		zoom_factor;

	fractol = (t_fractol *)param;
	(void)xdelta;
	if (ydelta == 0)
		return ;
	mlx_get_mouse_pos(fractol->mlx, &mouse_x, &mouse_y);
	if (mouse_x < 0 || mouse_x >= WIDTH
		|| mouse_y < 0 || mouse_y >= HEIGHT)
		return ;
	if (ydelta > 0)
		zoom_factor = 1.2;
	else
		zoom_factor = 0.8;
	calc_zoom(fractol, mouse_x, mouse_y, zoom_factor);
	fractol_render(fractol);
}

void	my_close(void *param)
{
	t_fractol	*f;

	f = (t_fractol *)param;
	clean_exit(f, 0);
}
