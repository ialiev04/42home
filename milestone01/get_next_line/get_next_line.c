/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:17:40 by ilaliev           #+#    #+#             */
/*   Updated: 2025/03/19 17:17:40 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buffer_to_stash(int fd, char *stash, char *buffer)
{
	
}

char *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*stash;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	stash = malloc(1);
	if (!stash)
		return (NULL);
	stash[0] = '\0';
	stash = buffer_to_stash(fd, stash, buffer);
	new_buffer()
	return (stash_to_line());
}
