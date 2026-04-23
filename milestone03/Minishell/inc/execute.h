/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 01:21:13 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/11 01:21:50 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_iofd_list
{
	int		stdin_fd;
	int		stdout_fd;
}	t_iofd_list;

# define SIG_NORMAL

#endif