/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:51:12 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/12 01:27:15 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void	clean_exit(t_fractol *fractol)
{
	if (fractol->img)
		mlx_delete_image(fractol->mlx, fractol->img);
	if (fractol->mlx)
		mlx_terminate(fractol->mlx);
	free(fractol->pixel);
	free(fractol);
	exit(0);
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
		clean_exit(fractol);
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->img)
		clean_exit(fractol);
	fractol->name = name;
	pixel->min_cd_r = -2.0;
	pixel->max_cd_r = 2.0;
	pixel->min_cd_i = -2.0;
	pixel->max_cd_i = 2.0;
	pixel->max_iter = 100;
	fractol->pixel = pixel;
	return (fractol);
}

double	ft_atof(char *s)
{
	double	res1;
	double	res2;
	int		len;
	int		norp;

	norp = 1;
	if (s[0] == '-')
	{
		norp = -1;
		s++;
	}
	res1 = (double)ft_atoi(s);
	while (*s && *s != '.')
		s++;
	s++;
	res2 = (double)ft_atoi(s);
	len = ft_strlen(s);
	while (len--)
		res2 = res2 / 10;
	return (norp * (res1 + res2));
}

void	init_julia(char *s1, char *s2, t_fractol *f)
{
	f->pixel->julia_r = ft_atof(s1); 
	f->pixel->julia_i = ft_atof(s2);
}
