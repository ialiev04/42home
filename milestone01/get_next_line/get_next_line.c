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

char	*stash_to_line(char *stash)
{
	char	*line;
	size_t	i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_substr(stash, 0, i);
	free(stash);
	if (!line)
		return (NULL);
	return (line);
}

char	*new_buffer(char	*buffer)
{
	char	*new_buf;

	if (!buffer)
		return (NULL);
	new_buf = ft_strchr(buffer, '\n');
	if (!new_buf)
		return (buffer + ft_strlen(buffer));
	return (new_buf + 1);
}

char	*join_helper(char *stash, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(stash, buffer);
	free(stash);
	if (!temp)
		return (NULL);
	return (temp);
}

char	*buffer_to_stash(int fd, char *stash, char *buffer)
{
	int		buffer_read;

	while (!ft_strchr(stash, '\n'))
	{
		buffer_read = read(fd, buffer, BUFFER_SIZE);
		if (buffer_read <= 0)
		{
			free(stash);
			return (NULL);
		}
		buffer[buffer_read] = '\0';
		stash = join_helper(stash, buffer);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

char *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*stash;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	stash = ft_strdup(buffer);
	if (!stash)
		return (NULL);
	stash = buffer_to_stash(fd, stash, buffer);
	if (!stash)
		return (NULL);
	buffer = new_buffer((char *)buffer);
	return (stash_to_line(stash));
}
