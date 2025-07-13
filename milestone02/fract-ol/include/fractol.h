/* ************************************************************************** */
/*																		    */
/*														:::      ::::::::   */
/*   fractol.h										  :+:      :+:    :+:   */
/*												    +:+ +:+		 +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+		+#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/06/27 16:25:37 by ilaliev		   #+#    #+#		     */
/*   Updated: 2025/07/13 17:36:53 by ilaliev		  ###   ########.fr		*/
/*																		    */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../ft_printf/ft_printf.h"
# include "../mini_libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>

# define WIDTH			512
# define HEIGHT			512

# define COLOR_BLACK	0x00000000
# define COLOR_1		0xFF00FFFF
# define COLOR_2		0xFF0099FF
# define COLOR_3		0xFF0066FF
# define COLOR_4		0xFF0033FF
# define COLOR_5		0xFF0000FF
# define COLOR_6		0xFF3300FF
# define COLOR_7		0xFF6600FF
# define COLOR_8		0xFF9900FF
# define COLOR_9		0xFFCC00FF
# define COLOR_10		0xFFFF00FF
# define COLOR_11		0xCCFF00FF
# define COLOR_12		0x99FF00FF
# define COLOR_13		0x66FF00FF
# define COLOR_14		0x33FF00FF
# define COLOR_15		0x00FF00FF
# define COLOR_16		0x00FF33FF
# define COLOR_17		0x00FF66FF
# define COLOR_18		0x00FF99FF
# define COLOR_19		0x00FFCCFF
# define COLOR_20		0x00FFFFFF
# define COLOR_21		0x0099FFFF
# define COLOR_22		0x0066FFFF
# define COLOR_23		0x0033FFFF

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
void		calc_mandel(t_pixel *pixel, t_fractol *fractol);
void		clean_exit(t_fractol *fractol, int error);
void		event_handler(t_fractol *fractol);
double		ft_atof(char *s, t_fractol *f);
void		init_julia(char *s1, char *s2, t_fractol *f);
t_fractol	*fractol_init(char *name);
void		calc_julia(t_pixel *pixel, t_fractol *fractol);
void		handle_movement_keys(mlx_key_data_t event, t_fractol *fractol);
void		my_key(mlx_key_data_t event, void *param);
void		my_scroll(double xdelta, double ydelta, void *param);
void		my_close(void *param);
int			error_msg(void);
int			main(int ac, char **av);

#endif