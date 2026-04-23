/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 06:36:55 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/07 06:37:49 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	free_child(int *last_exit_status, t_cmd_list *cmd_list, char *input)
{
	int	ret;

	ret = *last_exit_status;
	free_env_list(cmd_list->env_list);
	free_cmd_list(cmd_list);
	free(last_exit_status);
	free(input);
	return (ret);
}
