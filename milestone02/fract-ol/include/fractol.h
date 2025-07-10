/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:25:37 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/10 16:15:02 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define WIDTH 800
# define HEIGHT 800

# define MIN_REAL		-2.0
# define MAX_REAL		1.0
# define MIN_IMAG		-1.5
# define MAX_IMAG		1.5
# define MAX_ITER		1000

# define COLOR_WHITE	0xFFFFFFFF
# define COLOR_BLACK	0x000000FF
# define COLOR_RED		0xFF0000FF
# define COLOR_GREEN	0x00FF00FF
# define COLOR_BLUE		0x0000FFFF
# define COLOR_YELLOW	0xFFFF00FF
# define COLOR_CYAN		0x00FFFFFF
# define COLOR_MAGENTA	0xFF00FFFF
# define COLOR_GRAY		0x808080FF
# define COLOR_ORANGE	0xFFA500FF
# define COLOR_PINK		0xFFC0CBFF
# define COLOR_PURPLE	0x800080FF
# define COLOR_BROWN	0xA52A2AFF
# define COLOR_LIME		0xBFFF00FF
# define COLOR_SKYBLUE	0x87CEEBFF

typedef struct s_pixel
{
	double	real_part;
	double	imag_part;
	int		real_coord;
	int		imag_coord;
}	t_pixel;

typedef struct s_fractol
{
	char	*name;
	void	*mlx;
	void	*img;
	t_pixel	*pixel;
}	t_fractol;

void	fractol_render(t_fractol *fractol);
void	find_and_display(int x, int y, t_pixel *pixel, t_fractol *fractol);
void	calc_mandel(t_pixel *pixel, t_fractol *fractol);

#endif