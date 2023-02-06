/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:15:10 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 18:18:34 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	execute_cmd(t_data *data)
{
	int		stdin_saved;
	int		stdout_saved;

	data->cur.idx_cmd = 0;
	while (data->cur.idx_cmd < data->cur.table->qty_cmd)
	{
		data->cur.cmd = (data->cur.table->cmd + data->cur.idx_cmd);
		save_std_fd(&stdin_saved, &stdout_saved);
		replace_tokens(data);
		set_redirects(data);
		execute(data);
		unset_env_var_full(data);
		close_std_fd(&stdin_saved, &stdout_saved);
		set_last_cmd_env(data);
		set_exit_status_env(data);
		data->cur.idx_cmd++;
	}
}
