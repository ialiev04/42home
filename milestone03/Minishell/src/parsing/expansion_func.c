/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 21:53:40 by yuerliu           #+#    #+#             */
/*   Updated: 2026/03/11 02:08:08 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <string.h>

char	*get_var_name(char *str, int *i)
{
	int		start;
	int		len;

	(*i)++;
	start = *i;
	len = 0;
	if (str[*i] == '?')
	{
		(*i)++;
		return (ft_strdup("?"));
	}
	while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
	{
		(*i)++;
		len++;
	}
	if (len == 0)
		return (NULL);
	return (ft_substr(str, start, len));
}

char	*get_var_value(char *var_name, t_env_list *env_list,
			int last_exit_status)
{
	t_env_node	*current;

	if (!var_name)
		return (ft_strdup("$"));
	if (ft_strncmp(var_name, "?", 2) == 0)
	{
		free(var_name);
		return (ft_itoa(last_exit_status));
	}
	current = env_list->head;
	while (current)
	{
		if (ft_strncmp(current->key, var_name, ft_strlen(var_name) + 1) == 0)
		{
			free(var_name);
			return (ft_strdup(current->value));
		}
		current = current->next;
	}
	free(var_name);
	return (ft_strdup(""));
}

char	*expand_in_double_quotes(char *str, t_env_list *env_list,
		int last_exit_status)
{
	char	*result;
	char	*temp;
	int		i;
	int		start;

	result = ft_strdup("");
	i = 1;
	start = i;
	while (str[i] && str[i] != '"')
	{
		if (str[i] == '$')
		{
			temp = ft_substr(str, start, i - start);
			result = ft_strjoin_free(result, temp);
			temp = get_var_value(get_var_name(str, &i), env_list,
					last_exit_status);
			result = ft_strjoin_free(result, temp);
			start = i;
		}
		else
			i++;
	}
	temp = ft_substr(str, start, i - start);
	return (ft_strjoin_free(result, temp));
}
