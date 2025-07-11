/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:25:37 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/11 04:36:58 by ilaliev          ###   ########.fr       */
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

# define WIDTH			1000
# define HEIGHT			1000
# define MAX_ITER		100

# define COLOR_BLACK	0x000000FF
# define COLOR_2		0xFF800080
# define COLOR_3		0xFFFF0080
# define COLOR_4		0xFF0080FF
# define COLOR_5		0xFFFF8000
# define COLOR_6		0xFF4000FF
# define COLOR_7		0xFF00FF40
# define COLOR_8		0xFF8040FF
# define COLOR_9		0xFFFF4080
# define COLOR_10		0xFF4080FF
# define COLOR_11		0xFFFF8040
# define COLOR_12		0xFF0040FF
# define COLOR_13		0xFFFF4000

typedef struct s_pixel
{
	double	real_part;
	double	imag_part;
	int		real_coord;
	int		imag_coord;
	double	min_cd_r;
	double	min_cd_i;
	double	max_cd_r;
	double	max_cd_i;
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
void	clean_exit(t_fractol *fractol);
void	event_handler(t_fractol *fractol);
int		main(int ac, char **av);

#endif