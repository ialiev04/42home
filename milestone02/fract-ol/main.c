/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:38:47 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/12 01:53:51 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

int	main(int ac, char **av)
{
	t_fractol	*fractol;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		|| (ac == 4 && !ft_strncmp(av [1], "julia", 5)))
	{
		fractol = fractol_init(av[1]);
		if (ac == 4)
			init_julia(av[2], av[3], fractol);
		fractol_render(fractol);
		event_handler(fractol);	
	}
	else
		return(invalid_input());	//error_message(); //todo
}
