/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 19:10:50 by riri              #+#    #+#             */
/*   Updated: 2026/03/11 01:33:24 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_env_node(t_env_list *env_list, char *entry, int key_len)
{
	t_env_node	*node;
	char		*value;

	node = malloc(sizeof(t_env_node));
	if (!node)
		return ;
	value = ft_strchr(entry, '=');
	if (!value)
		return ;
	node->key = ft_substr(entry, 0, key_len);
	node->value = ft_strdup(value + 1);
	node->next = NULL;
	if (!env_list->head)
		env_list->head = node;
	else
		env_list->tail->next = node;
	env_list->tail = node;
	env_list->size++;
}

t_env_list	*init_env_list(char **envp)
{
	t_env_list	*env_list;
	char		*equal_sign;
	int			i;

	env_list = malloc(sizeof(t_env_list));
	if (!env_list)
		return (NULL);
	env_list->head = NULL;
	env_list->tail = NULL;
	env_list->size = 0;
	i = 0;
	while (envp[i])
	{
		equal_sign = ft_strchr(envp[i], '=');
		if (equal_sign)
			add_env_node(env_list, envp[i], equal_sign - envp[i]);
		i++;
	}
	return (env_list);
}
