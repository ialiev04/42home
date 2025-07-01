/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:38:47 by ilaliev           #+#    #+#             */
/*   Updated: 2025/06/29 16:38:06 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(param);
}

int	maint(int ac, char **av)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		|| (ac == 4 && ft_strncmp(av [1], "julia", 5)))
	{
		t_fractol = mlx_init()
	}
	else
		error_message() //todo
	
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		return (1);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		return (1);
	mlx_put_pixel(img, 100, 100, COLOR_PINK);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
