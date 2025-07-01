/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:25:37 by ilaliev           #+#    #+#             */
/*   Updated: 2025/06/29 16:46:55 by ilaliev          ###   ########.fr       */
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

# define WIDTH 512
# define HEIGHT 512

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

typedef struct	s_pixel
{
	void	*img_ptr;
	char	*current_ptr;
	int		bits;
}	t_pixel;

typedef struct	s_fractol
{
	char	*name;
	void	*mlx;
	void	*img;
	t_pixel	pixel;
}	t_fractol;



#endif