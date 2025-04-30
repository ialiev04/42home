/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:24:02 by ilaliev           #+#    #+#             */
/*   Updated: 2025/04/23 11:08:17 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	compare_lines(int fd, int len_first_line)
{
	char	*line;
	int		len_current_line;

	len_current_line = 1;
	while (len_current_line != 0)
	{
		line = get_next_line(fd);
		if (!line)
		{
			close(fd);
			error_message(3);
		}
		len_current_line = ft_strlen(line);
		if (line[len_current_line - 1] != '\n')
			len_current_line++;
		free(line);
		if (len_first_line != len_current_line)
		{
			close(fd);
			error_message(4);
		}
	}
}

void	is_map_rectangular(char *av)
{
	char	*line;
	int		fd;
	int		len_first_line;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		error_message(3);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		error_message(3);
	}
	len_first_line = ft_strlen(line);
	free (line);
	compare_lines(fd, len_first_line);
	close(fd);
}
