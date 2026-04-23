/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 02:22:22 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/11 02:22:37 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <string.h>

static char	*handle_tilde(char *str, t_env_list *env_list,
			int last_exit_status, int *i)
{
	if (str[0] == '~' && (str[1] == '/' || str[1] == '\0'))
	{
		*i = 1;
		return (get_var_value(ft_strdup("HOME"), env_list, last_exit_status));
	}
	return (ft_strdup(""));
}

static void	handle_single_quote(char *str, int *i, char **result)
{
	int		start;
	char	*segment;

	start = ++(*i);
	while (str[*i] && str[*i] != '\'')
		(*i)++;
	segment = ft_substr(str, start, *i - start);
	*result = ft_strjoin_free(*result, segment);
	if (str[*i] == '\'')
		(*i)++;
}

static void	handle_double_quote(char *str, int *i, char **result,
			t_expand_ctx *ctx)
{
	int		start;
	char	*segment;
	char	*expanded;
	size_t	len;

	start = *i;
	(*i)++;
	while (str[*i] && str[*i] != '"')
		(*i)++;
	if (str[*i] == '"')
		len = *i - start + 1;
	else
		len = *i - start;
	segment = ft_substr(str, start, len);
	expanded = expand_in_double_quotes(segment, ctx->env, ctx->status);
	free(segment);
	*result = ft_strjoin_free(*result, expanded);
	if (str[*i] == '"')
		(*i)++;
}

static void	handle_regular(char *str, int *i, char **result, t_expand_ctx *ctx)
{
	int		start;
	char	*segment;
	char	*expanded;

	if (str[*i] == '$' && (str[*i + 1] == '"' || str[*i + 1] == '\''))
	{
		(*i)++;
		return ;
	}
	start = *i;
	while (str[*i] && str[*i] != '"' && str[*i] != '\'')
		(*i)++;
	segment = ft_substr(str, start, *i - start);
	expanded = expand_regular(segment, ctx->env, ctx->status);
	free(segment);
	*result = ft_strjoin_free(*result, expanded);
}

char	*expand_variables(char *str, t_env_list *env_list, int last_exit_status)
{
	char			*result;
	int				i;
	t_expand_ctx	ctx;

	if (!str)
		return (NULL);
	ctx.env = env_list;
	ctx.status = last_exit_status;
	i = 0;
	result = handle_tilde(str, env_list, last_exit_status, &i);
	if (!result)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\'')
			handle_single_quote(str, &i, &result);
		else if (str[i] == '"')
			handle_double_quote(str, &i, &result, &ctx);
		else
			handle_regular(str, &i, &result, &ctx);
	}
	return (result);
}
