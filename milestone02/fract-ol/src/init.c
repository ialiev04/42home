/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:49:04 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/17 15:33:14 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_julia(char *s1, char *s2, t_fractol *f)
{
	f->pixel->julia_r = ft_atof(s1, f);
	f->pixel->julia_i = ft_atof(s2, f);
}

static void	init_pixel(t_pixel *p)
{
	p->min_cd_r = -2.0;
	p->max_cd_r = 2.0;
	p->min_cd_i = -2.0;
	p->max_cd_i = 2.0;
	p->max_iter = 100;
	p->color_palette = 0;
}

t_fractol	*fractol_init(char *name)
{
	t_fractol	*fractol;
	t_pixel		*pixel;

	fractol = malloc(sizeof(t_fractol));
	if (!fractol)
		exit(1);
	pixel = malloc(sizeof(t_pixel));
	if (!pixel)
	{
		free(fractol);
		exit(1);
	}
	fractol->mlx = mlx_init(WIDTH, HEIGHT, name, true);
	if (!fractol->mlx)
		clean_exit(fractol, 0);
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->img)
		clean_exit(fractol, 0);
	fractol->name = name;
	fractol->pixel = pixel;
	init_pixel(fractol->pixel);
	return (fractol);
}
