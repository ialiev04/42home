/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 05:59:05 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/07 06:16:38 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	invalid_error(t_cmd_node *cmd_node, int *last_exit_status, int i)
{
	ft_putstr_fd("export: `", STDERR_FILENO);
	ft_putstr_fd(cmd_node->cmd[i], STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
	*last_exit_status = 1;
}

char	*get_env_value(t_env_list *env_list, const char *key)
{
	t_env_node	*current;

	if (!env_list || !key)
		return (NULL);
	current = env_list->head;
	while (current)
	{
		if (ft_strlen(current->key) == ft_strlen(key)
			&& ft_strncmp(current->key, key, ft_strlen(current->key)) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

void	update_env(t_env_list *env_list, const char *old, const char *new)
{
	t_env_node	*current;

	if (!env_list || !old)
		return ;
	current = env_list->head;
	while (current)
	{
		if (strcmp(current->key, old) == 0)
		{
			free(current->value);
			current->value = strdup(new);
			return ;
		}
		current = current->next;
	}
}
