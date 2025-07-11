/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:25:37 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/11 21:55:08 by ilaliev          ###   ########.fr       */
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

# define WIDTH			512
# define HEIGHT			512

# define COLOR_BLACK   0x00000000
# define COLOR_1        0xFF00FFFF  // Cyan
# define COLOR_2        0x00FFFFFF  // Bright Aqua
# define COLOR_3        0x00FF66FF  // Neon Pink
# define COLOR_4        0xFF0066FF  // Hot Red-Pink
# define COLOR_5        0xFF3300FF  // Electric Red
# define COLOR_6        0xFF6600FF  // Vivid Orange-Red
# define COLOR_7        0xFFFF0000  // Bright Red
# define COLOR_8        0xFFFF6600  // Neon Orange
# define COLOR_9        0xFFFFCC00  // Bright Yellow
# define COLOR_10       0xCCFF00FF  // Chartreuse
# define COLOR_11       0x66FF00FF  // Acid Green
# define COLOR_12       0x00FF00FF  // Bright Green
# define COLOR_13       0x00FF66FF  // Neon Lime
# define COLOR_14       0x00FFCCFF  // Minty Aqua
# define COLOR_15       0x3399FFFF  // Sky Blue
# define COLOR_16       0x0033FFFF  // Electric Blue
# define COLOR_17       0x0000FFFF  // Pure Blue
# define COLOR_18       0x6600FFFF  // Neon Indigo
# define COLOR_19       0x9900FFFF  // Vivid Violet
# define COLOR_20       0xCC00FFFF  // Bright Purple
# define COLOR_21       0xFF00CCFF  // Neon Magenta
# define COLOR_22       0xFF0099FF  // Shocking Pink
# define COLOR_23       0xFF0033FF  // Vivid Rose


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
	int		max_iter;
	double	julia_r;
	double	julia_i;
}	t_pixel;

typedef struct s_fractol
{
	char	*name;
	void	*mlx;
	void	*img;
	t_pixel	*pixel;
}	t_fractol;

void		fractol_render(t_fractol *fractol);
void		find_and_display(int x, int y, t_pixel *pixel, t_fractol *fractol);
void		calc_mandel(t_pixel *pixel, t_fractol *fractol);
void		clean_exit(t_fractol *fractol);
void		event_handler(t_fractol *fractol);
double		ft_atof(char *s);
void		init_julia(char *s1, char *s2, t_fractol *f);
t_fractol	*fractol_init(char *name);
void		calc_julia(t_pixel *pixel, t_fractol *fractol);
int			main(int ac, char **av);

#endif