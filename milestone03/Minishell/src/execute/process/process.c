/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 06:22:25 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/07 06:54:17 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	check_cmd_or_builtin(t_cmd_node *node, int *last_exit_status,
			t_cmd_list *cmd_list, char *input)
{
	t_env_list	*env_list;

	env_list = cmd_list->env_list;
	if (setup_redir(node) == -1)
	{
		*last_exit_status = 1;
		return ;
	}
	if (node->cmd_type == CMD)
		execute_cmd(node, last_exit_status, cmd_list, input);
	else if (node->cmd_type == BUILTIN)
		check_what_builtin(node, env_list, last_exit_status);
	else if (node->cmd[0] != NULL)
		perror("command not found\n");
}

static void	wait_for_children(pid_t last_pid, int *last_exit_status)
{
	int		status;
	pid_t	pid;

	mute_signals();
	while (1)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == -1)
			break ;
		if (pid == last_pid)
		{
			if (WIFEXITED(status))
				*last_exit_status = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				*last_exit_status = 128 + WTERMSIG(status);
		}
	}
	handle_signals_main();
}

static void	setup_child_pipes(int *fd, int prev_fd, int has_next)
{
	if (prev_fd != -1)
	{
		dup2(prev_fd, STDIN_FILENO);
		close(prev_fd);
	}
	if (has_next)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
	}
}

static int	setup_parent_pipes(int *fd, int *prev_fd, int has_next)
{
	if (has_next)
		close(fd[1]);
	if (*prev_fd != -1)
		close(*prev_fd);
	if (has_next)
		*prev_fd = fd[0];
	return (0);
}

int	process(t_cmd_list *cmd_list, int *last_exit_status, char *input)
{
	int			fd[2];
	int			prev_fd;
	pid_t		pid;
	t_cmd_node	*current;

	prev_fd = -1;
	current = cmd_list->head;
	if (current->next == NULL && current->cmd_type == BUILTIN)
		return (check_what_builtin(cmd_list->head,
				cmd_list->env_list, last_exit_status));
	while (current != NULL)
	{
		if (current->next != NULL)
			pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			setup_child_pipes(fd, prev_fd, current->next != NULL);
			check_cmd_or_builtin(current, last_exit_status, cmd_list, input);
			exit(free_child(last_exit_status, cmd_list, input));
		}
		setup_parent_pipes(fd, &prev_fd, current->next != NULL);
		current = current->next;
	}
	return (wait_for_children(pid, last_exit_status), 0);
}
