/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:01:54 by dpestana          #+#    #+#             */
/*   Updated: 2023/01/16 09:43:26 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	non_builtin(t_data *data)
{
	int	pid;
	int	wait_status;

	pid = fork();
	wait_status = 0;
	if (pid == 0)
		children_process(data);
	close_fd(data);
	waitpid(pid, &wait_status, 0);
	if (WIFEXITED(wait_status))
		data->exit_status = WEXITSTATUS(wait_status);
	else if (WIFSIGNALED(wait_status))
		data->exit_status = WTERMSIG(wait_status);
}
