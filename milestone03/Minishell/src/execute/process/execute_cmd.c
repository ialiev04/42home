/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 06:22:20 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/10 00:34:11 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static char	**free_partial_env(char **env, int i)
{
	while (i >= 0)
		free(env[i--]);
	free(env);
	return (NULL);
}

static char	**format_env(t_env_list *env_list)
{
	char		**formatted_env;
	t_env_node	*current;
	int			i;

	if (!env_list)
		return (NULL);
	formatted_env = malloc((env_list->size + 1) * sizeof(char *));
	if (!formatted_env)
		return (NULL);
	current = env_list->head;
	i = 0;
	while (i < env_list->size && current)
	{
		formatted_env[i] = key_plus_val(current);
		if (!formatted_env[i])
			return (free_partial_env(formatted_env, i - 1));
		current = current->next;
		i++;
	}
	formatted_env[i] = NULL;
	return (formatted_env);
}

static char	*check_path(char *cmd, t_env_list *env_list)
{
	char	*ret_val;

	if (cmd == NULL)
		return (NULL);
	if (ft_strchr(cmd, '/') != NULL)
	{
		if (access(cmd, F_OK) == 0)
			ret_val = ft_strdup(cmd);
		else
			return (NULL);
	}
	else
		ret_val = find_path(cmd, env_list);
	if (ret_val == NULL)
		return (NULL);
	return (ret_val);
}

void	cmd_error(t_cmd_list *list, t_env_list *env_list,
			int *last_exit_status, char *input)
{
	int	last_exit;

	last_exit = *last_exit_status;
	free(input);
	free_cmd_list(list);
	free_env_list(env_list);
	free(last_exit_status);
	exit(last_exit);
}

void	execute_cmd(t_cmd_node *node, int *last_exit_status,
			t_cmd_list *cmd_list, char *input)
{
	char	*path;
	char	**argv;
	char	**envp;

	argv = node->cmd;
	envp = format_env(cmd_list->env_list);
	if (envp == NULL)
	{
		*last_exit_status = 1;
		return ;
	}
	path = check_path(node->cmd[0], cmd_list->env_list);
	if (!path)
	{
		*last_exit_status = 127;
		perror("");
		free_argv(envp);
		cmd_error(cmd_list, cmd_list->env_list, last_exit_status, input);
	}
	execve(path, argv, envp);
	free(path);
	free_argv(envp);
	cmd_error(cmd_list, cmd_list->env_list, last_exit_status, input);
}
