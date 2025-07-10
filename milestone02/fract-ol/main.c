/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:38:47 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/10 15:58:51 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

static t_fractol	*fractol_init(char *name)
{
	t_fractol	*fractol;
	t_pixel		*pixel;

	fractol->mlx = mlx_init(WIDTH, HEIGHT, name, true);
	if (!fractol->mlx)
		exit(1);	//redo
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->img)
		exit(1);	//redo
	fractol->name = name;
	pixel->real_part = MIN_REAL;
	pixel->imag_part = MIN_IMAG;
	pixel->real_coord = 0;
	pixel->imag_coord = 0;
	fractol->pixel = pixel;
	return (fractol);
}

int	main(int ac, char **av)
{
	t_fractol	*fractol;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		|| (ac == 4 && ft_strncmp(av [1], "julia", 5)))
	{
		fractol = fractol_init(av[1]);
		fractol_render(fractol);
		mlx_loop
	}
	else
		exit(1);	//error_message(); //todo
	return (0);
}
