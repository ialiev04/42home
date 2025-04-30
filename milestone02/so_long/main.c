/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:51:32 by ilaliev           #+#    #+#             */
/*   Updated: 2025/04/23 12:41:15 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	error_code table:
	(1) ac != 2
	(2) av[1] != .ber file
	(3) trouble opening .ber file
	(4) .ber map not rectangular
*/

void	error_message(int error_code)
{
	if (error_code == 1)
		ft_printf();
	if (error_code == 2)
		ft_printf();
	// room for errors
	exit(1);
}

void	validate_input(int ac, char **av)
{
	char	*last_dot;

	if (ac != 2)
		error_message(1);
	last_dot = ft_strrchr(av[1], '.');
	if (!last_dot || (ft_strncmp(last_dot, ".ber\0", 5) != 0))
		error_message(2);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	validate_input(ac, av);
	init_map(ac, av);

	// init all lists and variables

	// game hook

	// end programm
}
