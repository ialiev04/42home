/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_regular.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 01:32:12 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/11 02:14:42 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_regular(char *str, t_env_list *env_list, int last_exit_status)
{
	char	*result;
	char	*tmp;
	int		i;
	int		start;
	char	*value;

	result = ft_strdup("");
	i = 0;
	start = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			tmp = ft_substr(str, start, i - start);
			result = ft_strjoin_free(result, tmp);
			tmp = get_var_name(str, &i);
			value = get_var_value(tmp, env_list, last_exit_status);
			result = ft_strjoin_free(result, value);
			start = i;
		}
		else
			i++;
	}
	tmp = ft_substr(str, start, i - start);
	return (ft_strjoin_free(result, tmp));
}
