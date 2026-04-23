/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 01:22:31 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/11 01:22:34 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_file_node	*create_file_node(char *filename, int redir_type)
{
	t_file_node	*node;

	node = malloc(sizeof(t_file_node));
	if (!node)
		return (NULL);
	node->filename = filename;
	node->redir_type = redir_type;
	node->next = NULL;
	return (node);
}

void	add_file_node(t_file_list *list, t_file_node *node)
{
	if (!list || !node)
		return ;
	if (!list->head)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		list->tail->next = node;
		list->tail = node;
	}
	list->size++;
}

t_cmd_node	*create_cmd_node(void)
{
	t_cmd_node	*node;

	node = malloc(sizeof(t_cmd_node));
	if (!node)
		return (NULL);
	node->cmd_type = CMD;
	node->cmd = NULL;
	node->files = NULL;
	node->next = NULL;
	return (node);
}

void	add_cmd_node(t_cmd_list *list, t_cmd_node *node)
{
	if (!list || !node)
		return ;
	if (!list->head)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		list->tail->next = node;
		list->tail = node;
	}
	list->size++;
}
