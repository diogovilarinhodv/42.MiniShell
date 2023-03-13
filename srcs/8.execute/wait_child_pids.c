/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_child_pids.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:33:19 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/12 23:48:28 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	wait_child_pids(t_data *data)
{
	int	wait_status;

	data->cur.idx_cmd = 0;
	while (data->cur.idx_cmd < data->cur.table->qty_cmd)
	{
		wait_status = 0;
		data->cur.cmd = (data->cur.table->cmd + data->cur.idx_cmd);
		if (data->cur.cmd->is_builtin == NO && data->cur.cmd->no_exec_heredoc == NO)
		{
			waitpid(data->cur.cmd->pid, &wait_status, 0);
			if (WIFEXITED(wait_status))
				data->exit_status = WEXITSTATUS(wait_status);
			else if (WIFSIGNALED(wait_status))
				data->exit_status = WTERMSIG(wait_status);
		}
		data->cur.idx_cmd++;
	}
}
