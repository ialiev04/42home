/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 05:47:32 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/07 05:52:16 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static t_env_node	**copy_list(t_env_list *env_list)
{
	t_env_node	**copied_list;
	t_env_node	*current;
	int			i;

	copied_list = malloc((env_list->size + 1) * sizeof(t_env_node *));
	if (!copied_list)
		return (NULL);
	current = env_list->head;
	i = 0;
	while (current != NULL)
	{
		copied_list[i] = current;
		current = current->next;
		i++;
	}
	copied_list[i] = NULL;
	return (copied_list);
}

t_env_node	**sort_list(t_env_list *env_list)
{
	t_env_node	**copied_list;
	t_env_node	*tmp;
	int			i;

	copied_list = copy_list(env_list);
	if (copied_list == NULL)
		return (NULL);
	i = 0;
	while (1)
	{
		if (copied_list[i + 1] == NULL)
			break ;
		if (ft_strncmp(copied_list[i]->key, copied_list[i + 1]->key,
				ft_strlen(copied_list[i]->key)) > 0)
		{
			tmp = copied_list[i];
			copied_list[i] = copied_list[i + 1];
			copied_list[i + 1] = tmp;
			i = 0;
		}
		i++;
	}
	return (copied_list);
}

int	is_valid_key(char *str)
{
	int	i;

	if (str == NULL || str[0] == '\0')
		return (0);
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	i = 1;
	while (str[i] != '\0')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}
