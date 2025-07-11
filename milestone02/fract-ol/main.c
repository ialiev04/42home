/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:38:47 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/11 03:57:48 by ilaliev          ###   ########.fr       */
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

static t_fractol	*fractol_init(char *name)
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
		printf("came here\n");
		event_handler(fractol);
	}
	else
		exit(1);	//error_message(); //todo
	return (0);
}
