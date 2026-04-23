/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 05:57:04 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/07 06:10:54 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static char	*get_home_or_path(t_cmd_node *cmd_node, t_env_list *env_list)
{
	char	*home;

	if (!cmd_node->cmd[1])
	{
		home = get_env_value(env_list, "HOME");
		if (!home)
			printf("minishell: cd: HOME not set\n");
		return (home);
	}
	return (cmd_node->cmd[1]);
}

static char	*resolve_home_path(const char *path, t_env_list *env_list)
{
	char	*home;
	char	*resolved;
	size_t	len;

	home = get_env_value(env_list, "HOME");
	if (!home)
		return (NULL);
	len = ft_strlen(home) + ft_strlen(path);
	resolved = malloc(len);
	if (!resolved)
		return (NULL);
	ft_strlcpy(resolved, home, len);
	ft_strlcat(resolved, path + 1, len);
	return (resolved);
}

static char	*resolve_path(const char *path, t_env_list *env_list)
{
	if (!path || path[0] == '\0')
		return (ft_strdup(get_env_value(env_list, "HOME")));
	if (path[0] == '~')
		return (resolve_home_path(path, env_list));
	return (ft_strdup(path));
}

int	builtin_cd(t_cmd_node *cmd_node, t_env_list *env_list,
		int *last_exit_status)
{
	char	*path;
	char	*resolved_path;
	char	cwd[PATH_MAX];

	if (!cmd_node || !cmd_node->cmd)
		return (0);
	if (cmd_node->cmd[2] != NULL && cmd_node->cmd[1])
		printf("minishell: cd: too many arguments\n");
	path = get_home_or_path(cmd_node, env_list);
	if (!path)
		return (1);
	resolved_path = resolve_path(path, env_list);
	if (!resolved_path || chdir(resolved_path) == -1)
		return (perror("No such file or directory\n"), free(resolved_path), 1);
	*last_exit_status = 0;
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		update_env(env_list, "OLDPWD", get_env_value(env_list, "PWD"));
		update_env(env_list, "PWD", cwd);
	}
	else
		*last_exit_status = 1;
	return (free(resolved_path), 0);
}
