/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 05:47:37 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/07 05:51:45 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_pwd(int *last_exit_status)
{
	char	*s;

	s = getcwd(NULL, 0);
	if (s == NULL)
	{
		*last_exit_status = 1;
		perror("pwd: error retrieving current directory: getcwd: ");
		perror("cannot access parent directories: No such file or directory");
		return ;
	}
	ft_putstr_fd(s, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	free(s);
	*last_exit_status = 0;
}
