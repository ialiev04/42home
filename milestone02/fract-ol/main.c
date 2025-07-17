/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:38:47 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/17 17:55:10 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

int	main(int ac, char **av)
{
	t_fractol	*fractol;

	if (check_input(ac, av) == 0)
	{
		fractol = fractol_init(av[1]);
		if (ac == 4)
			init_julia(av[2], av[3], fractol);
		fractol_render(fractol);
		event_handler(fractol);
	}
	else
		return (error_msg());
}

int	check_input(int ac, char **av)
{
	if (ac != 2 && ac != 4)
		return (1);
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot\0", 11))
		return (0);
	else if (ac == 2 && !ft_strncmp(av[1], "multibrot\0", 10))
		return (0);
	else if (ac == 4 && !ft_strncmp(av[1], "julia\0", 6))
		return (0);
	return (1);
}

void	event_handler(t_fractol *fractol)
{
	mlx_key_hook(fractol->mlx, my_key, fractol);
	mlx_scroll_hook(fractol->mlx, my_scroll, fractol);
	mlx_close_hook(fractol->mlx, my_close, fractol);
	mlx_loop(fractol->mlx);
}
