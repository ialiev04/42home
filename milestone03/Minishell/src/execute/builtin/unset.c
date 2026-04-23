/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 05:47:41 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/07 05:55:06 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	unset_first(t_env_list *env_list, t_env_node *tmp)
{
	env_list->head = tmp->next;
	env_list->size = env_list->size - 1;
	if (env_list->size == 1)
		env_list->tail = NULL;
	free(tmp->key);
	free(tmp->value);
	free(tmp);
	if (env_list->size == 0)
		env_list->head = NULL;
}

void	unset_middle(t_env_list *env_list, t_env_node *last, t_env_node *tmp)
{
	last->next = tmp->next;
	env_list->size = env_list->size - 1;
	if (env_list->size == 1)
		env_list->tail = NULL;
	free(tmp->key);
	free(tmp->value);
	free(tmp);
	if (env_list->size == 0)
		env_list->head = NULL;
}

static void	what_unset(t_env_list *env_list, t_env_node	*last,
				t_env_node	*tmp)
{
	if (last == NULL)
		unset_first(env_list, env_list->head);
	else
		unset_middle(env_list, last, tmp);
}

void	builtin_unset(t_cmd_node *cmd_node, t_env_list *env_list,
			int *last_exit_status)
{
	t_env_node	*tmp;
	t_env_node	*last;
	int			i;

	i = 1;
	while (cmd_node->cmd[i] != NULL)
	{
		tmp = env_list->head;
		last = NULL;
		while (tmp != NULL)
		{
			if (ft_strncmp(tmp->key, cmd_node->cmd[i],
					ft_strlen(cmd_node->cmd[i]) + 1) == 0)
			{
				what_unset(env_list, last, tmp);
				break ;
			}
			last = tmp;
			tmp = tmp->next;
		}
		i++;
	}
	*last_exit_status = 0;
}
