/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:19:58 by ilaliev           #+#    #+#             */
/*   Updated: 2025/04/23 12:38:00 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

//	libraries
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_map
{
	char	**map;
	int		height;	
	int		width;
	int		monitor_width;
	int		monitor_height;
	float	scale_x;
	float	scale_y;
	mlx_t	*mlx;
}	t_map;

typedef struct s_game
{
	t_map	map;
}	t_game;

#endif