/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 01:31:39 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/11 01:31:43 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;
	int		len;
	int		len1;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len = len1 + ft_strlen(s2) + 1;
	result = malloc(len);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, len1 + 1);
	ft_strlcat(result, s2, len);
	free(s1);
	free(s2);
	return (result);
}

void	free_env_list(t_env_list *env_list)
{
	t_env_node	*current;
	t_env_node	*temp;

	if (!env_list)
		return ;
	current = env_list->head;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
	free(env_list);
}
