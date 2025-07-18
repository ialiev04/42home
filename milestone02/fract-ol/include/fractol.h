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

# include "../ft_printf/include/ft_printf.h"
# include "../mini_libft/include/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <math.h>

# define WIDTH			512
# define HEIGHT			512

# define COLOR_BLACK	0x000000FF

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
	int		color_palette;
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
int			check_input(int ac, char **av);
void		calc_multi(t_pixel *pixel, t_fractol *fractol);

#endif