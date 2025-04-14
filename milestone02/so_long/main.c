/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:51:32 by ilaliev           #+#    #+#             */
/*   Updated: 2025/04/14 18:57:12 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	error_code table:
	(1) ac != 2
	(2) av[1] != .ber file
*/

void	error_message(int error_code)
{
	if (error_code == 1)
		exit();
	if (error_code == 2)
		exit()
	// room for errors
}

void	validate_input(int ac, char **av)
{
	char *last_dot;

	if (ac != 2)
		error_message(1);
	last_dot = ft_strrchr(av[1], '.');
	if (!last_dot || (ft_strncmp(last_dot, ".ber", 4) != 0))
		error_message(2);
}

int	main(int ac, char **av)
{
	validate_input(ac, av);

	// map valid?

	// init all lists and variables

	// game hook

	// end programm
}
