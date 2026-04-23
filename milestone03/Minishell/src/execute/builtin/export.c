/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 05:47:35 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/07 06:16:33 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static int	print_export_var(t_env_list *env_list)
{
	t_env_node	**sorted_list;
	int			i;

	sorted_list = sort_list(env_list);
	if (sorted_list == NULL)
		return (0);
	i = 0;
	while (sorted_list[i] != NULL)
	{
		ft_putstr_fd(sorted_list[i]->key, STDOUT_FILENO);
		ft_putstr_fd("=", STDOUT_FILENO);
		ft_putchar_fd(34, STDOUT_FILENO);
		ft_putstr_fd(sorted_list[i]->value, STDOUT_FILENO);
		ft_putchar_fd(34, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		i++;
	}
	free(sorted_list);
	return (1);
}

static t_env_node	*find_or_create(t_env_list *env_list, char *key, char *val)
{
	t_env_node	*current;
	t_env_node	*new_node;

	current = env_list->head;
	while (current != NULL)
	{
		if (ft_strncmp(current->key, key, ft_strlen(current->key) + 1) == 0)
		{
			free(current->value);
			current->value = ft_strdup(val);
			return (current);
		}
		current = current->next;
	}
	new_node = malloc(sizeof(t_env_node));
	if (new_node == NULL)
		exit(1);
	new_node->key = ft_strdup(key);
	new_node->value = ft_strdup(val);
	new_node->next = NULL;
	return (new_node);
}

static void	add_env(t_env_list *env_list, char *key, char *value)
{
	t_env_node	*new_node;

	new_node = find_or_create(env_list, key, value);
	if (new_node && new_node != env_list->head && new_node->next == NULL
		&& new_node != env_list->tail)
	{
		if (env_list->head == NULL)
		{
			env_list->head = new_node;
			env_list->tail = new_node;
		}
		else
		{
			env_list->tail->next = new_node;
			env_list->tail = new_node;
		}
		env_list->size++;
	}
}

static void	export_vars(t_cmd_node *cmd_node, t_env_list *env_list,
		int *last_exit_status)
{
	int		i;
	char	*key;
	char	*value;
	char	*equal_sign;

	i = 1;
	while (cmd_node->cmd[i] != NULL)
	{
		equal_sign = ft_strchr(cmd_node->cmd[i], '=');
		if (equal_sign == NULL)
		{
			i++;
			continue ;
		}
		key = ft_substr(cmd_node->cmd[i], 0, equal_sign - cmd_node->cmd[i]);
		value = ft_strdup(equal_sign + 1);
		if (!is_valid_key(key))
			invalid_error(cmd_node, last_exit_status, i);
		else
			add_env(env_list, key, value);
		free(key);
		free(value);
		i++;
	}
}

void	builtin_export(t_cmd_node *cmd_node, t_env_list *env_list,
		int *last_exit_status)
{
	if (cmd_node->cmd[1] == NULL)
	{
		if (print_export_var(env_list) == 0)
		{
			*last_exit_status = 1;
			return ;
		}
	}
	else
		export_vars(cmd_node, env_list, last_exit_status);
}
