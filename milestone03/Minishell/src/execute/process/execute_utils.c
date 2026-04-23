/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 06:22:22 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/10 00:39:14 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	free_argv(char **argv)
{
	int	i;

	i = 0;
	if (!argv)
		return (1);
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	return (1);
}

char	*key_plus_val(t_env_node *cur)
{
	char	*ret;
	int		i;
	int		j;

	ret = malloc((ft_strlen(cur->key) + ft_strlen(cur->value) + 2)
			* sizeof(char));
	if (ret == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (cur->key[i] != '\0')
	{
		ret[i] = cur->key[i];
		i++;
	}
	ret[i++] = '=';
	while (cur->value[j] != '\0')
		ret[i++] = cur->value[j++];
	ret[i] = '\0';
	return (ret);
}

char	*find_path(char *cmd, t_env_list *env_lists)
{
	t_env_node	*path;
	char		**split_path;
	char		*path_to_check;
	char		*tmp;
	int			i;

	path = env_lists->head;
	while (path && ft_strncmp(path->key, "PATH", 4) != 0)
		path = path->next;
	if (!path)
		return (NULL);
	split_path = ft_split(path->value, ':');
	if (split_path == NULL)
		return (NULL);
	i = 0;
	while (split_path[i])
	{
		tmp = ft_strjoin(split_path[i++], "/");
		path_to_check = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path_to_check, X_OK) == 0)
			return (free_argv(split_path), path_to_check);
		free(path_to_check);
	}
	return (free_argv(split_path), NULL);
}
