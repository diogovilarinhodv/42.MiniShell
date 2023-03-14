/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:15:10 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/14 09:47:53 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	execute_cmd_cycle(t_data *data)
{
	replace_tokens_on_cmd(data);
	if (is_heredoc(data) == NO)
		replace_redirects(data);
	if (is_heredoc(data) == YES)
		execute_heredoc(data);
	if (data->cur.cmd->no_exec_heredoc == NO)
	{
		set_dup2(data);
		set_redirects(data);
		if (data->cur.cmd->token != NULL)
		{
			execute(data);
			unset_env_var_full(data);
			set_last_cmd_env(data);
		}
		if (is_heredoc(data) == YES)
			delete_heredoc(data);
	}
}

void	execute_cmd(t_data *data)
{
	int		stdin_saved;
	int		stdout_saved;

	data->cur.idx_cmd = 0;
	while (data->cur.idx_cmd < data->cur.table->qty_cmd)
	{
		data->cur.cmd = (data->cur.table->cmd + data->cur.idx_cmd);
		save_std_fd(&stdin_saved, &stdout_saved);
		execute_cmd_cycle(data);
		close_std_fd(&stdin_saved, &stdout_saved);
		data->cur.idx_cmd++;
	}
	wait_child_pids(data);
	set_exit_status_env(data);
}
