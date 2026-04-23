/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 01:31:53 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/11 01:31:57 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_cmd_files(t_file_node *file)
{
	t_file_node	*file_temp;

	while (file)
	{
		file_temp = file;
		file = file->next;
		free(file_temp->filename);
		free(file_temp);
	}
}

static void	free_cmd_argv(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		free(cmd[i++]);
	free(cmd);
}

void	free_cmd_list(t_cmd_list *cmd_list)
{
	t_cmd_node	*current;
	t_cmd_node	*temp;

	if (!cmd_list)
		return ;
	current = cmd_list->head;
	while (current)
	{
		temp = current;
		current = current->next;
		if (temp->cmd)
			free_cmd_argv(temp->cmd);
		if (temp->files)
		{
			free_cmd_files(temp->files->head);
			free(temp->files);
		}
		free(temp);
	}
	free(cmd_list);
}
