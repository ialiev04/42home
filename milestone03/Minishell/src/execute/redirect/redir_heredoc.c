/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 06:55:48 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/11 01:42:31 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static void	replace_env(char *line, t_env_list *env_list, int fd, int i)
{
	int			j;
	t_env_node	*current;

	while (line[i])
	{
		if (line[i] == '$' && (ft_isalpha(line[i + 1]) || line[i + 1] == '_'))
		{
			i++;
			j = i;
			while (ft_isalnum(line[j]) || line[j] == '_')
				j++;
			current = env_list->head;
			while (current)
			{
				if (ft_strncmp(current->key, &line[i], j - i) == 0
					&& current->key[j - i] == '\0')
					ft_putstr_fd(current->value, fd);
				current = current->next;
			}
			i = j;
		}
		else
			ft_putchar_fd(line[i++], fd);
	}
}

static int	process_heredoc_line(char *line, char *delim,
			t_env_list *env, int fd)
{
	if (g_signal_status == 131 || g_signal_status == -1)
	{
		if (g_signal_status == -1)
			g_signal_status = 0;
		return (free(line), -1);
	}
	if (ft_strlen(delim) == ft_strlen(line)
		&& !ft_strncmp(delim, line, ft_strlen(delim)))
		return (free(line), 0);
	if (ft_strchr(line, '$') != NULL)
		replace_env(line, env, fd, 0);
	else
		ft_putstr_fd(line, fd);
	ft_putchar_fd('\n', fd);
	return (free(line), 1);
}

static int	write_to_tmp(t_env_list *env_list, int tmp_file, char *delimeter)
{
	char	*line;
	int		status;

	handle_signals_heredoc();
	while (1)
	{
		if (isatty(STDIN_FILENO))
			line = readline("> ");
		else
		{
			line = get_next_line(STDIN_FILENO);
			if (line && ft_strchr(line, '\n'))
				*ft_strchr(line, '\n') = '\0';
		}
		if (line == NULL)
			return (-1);
		status = process_heredoc_line(line, delimeter, env_list, tmp_file);
		if (status <= 0)
			return (status);
	}
}

int	redir_heredoc(t_file_node *file_node, t_env_list *env_list, char *tmpfile)
{
	int	fd;

	fd = open(tmpfile, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (printf("problem opening tmp file\n"), -1);
	if (write_to_tmp(env_list, fd, file_node->filename) == -1)
	{
		if (g_signal_status == 130 || g_signal_status == 131)
			return (free(tmpfile), close(fd), -1);
		g_signal_status = -1;
		printf("minishell: warning: here-document at ");
		return (free(tmpfile), close(fd), -1);
	}
	close(fd);
	return (0);
}

int	heredoc_setup(t_cmd_list *cmd_list)
{
	t_cmd_node	*current_cmd;
	t_file_node	*current_f;
	char		*name;

	current_cmd = cmd_list->head;
	while (current_cmd != NULL)
	{
		current_f = current_cmd->files->head;
		while (current_f != NULL)
		{
			if (current_f->redir_type == HERE_DOC)
			{
				name = get_unique_name();
				if (!name)
					return (perror("error occured creating a tmp file"), -1);
				if (redir_heredoc(current_f, cmd_list->env_list, name) == -1)
					return (-1);
				free(current_f->filename);
				current_f->filename = name;
			}
			current_f = current_f->next;
		}
		current_cmd = current_cmd->next;
	}
	return (0);
}
