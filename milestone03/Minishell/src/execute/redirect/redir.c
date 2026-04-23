/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 06:55:54 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/07 06:55:55 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	redir_infile(t_file_node *file_node)
{
	int	infile_fd;

	if (access(file_node->filename, F_OK) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(file_node->filename, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (-1);
	}
	infile_fd = open(file_node->filename, O_RDONLY);
	if (infile_fd == -1)
		return (-1);
	if (dup2(infile_fd, STDIN_FILENO) == -1)
		return (ft_putstr_fd("Error using dup2(infile)stdin\n", 2), -1);
	if (file_node->redir_type == HERE_DOC)
		unlink(file_node->filename);
	close(infile_fd);
	return (0);
}

int	redir_outfile(t_file_node *file_node)
{
	int	outf_fd;

	outf_fd = open(file_node->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outf_fd == -1)
		return (ft_putstr_fd("something went wrong (permission)\n", 2), -1);
	if (dup2(outf_fd, STDOUT_FILENO) == -1)
		return (ft_putstr_fd("Error using dup2(infile)stdout\n", 2), -1);
	close (outf_fd);
	return (0);
}

int	redir_append(t_file_node *file_node)
{
	int	outf_fd;

	outf_fd = open(file_node->filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (outf_fd == -1)
		return (ft_putstr_fd("something went wrong (permission)\n", 2), -1);
	if (dup2(outf_fd, STDOUT_FILENO) == -1)
		return (ft_putstr_fd("Error using dup2(infile)stdout\n", 2), -1);
	close (outf_fd);
	return (0);
}
