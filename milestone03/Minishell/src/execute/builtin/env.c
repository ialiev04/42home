/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 05:46:12 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/07 05:47:09 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	builtin_env(t_env_list *env_list, int *last_exit_status)
{
	t_env_node	*tmp;

	tmp = env_list->head;
	while (tmp != NULL)
	{
		ft_putstr_fd(tmp->key, STDOUT_FILENO);
		ft_putstr_fd("=", STDOUT_FILENO);
		ft_putstr_fd(tmp->value, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		tmp = tmp->next;
	}
	*last_exit_status = 0;
}
