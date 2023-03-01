/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:15:10 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/01 15:49:56 by dpestana         ###   ########.fr       */
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
		replace_redirects(data);
		set_redirects(data);
		execute(data);
		unset_env_var_full(data);
		close_std_fd(&stdin_saved, &stdout_saved);
		set_last_cmd_env(data);
		if (new_exit_status()->is_ms == YES)
			data->exit_status = ft_atoi(new_exit_status()->new_value);
		printf("after execute_cmd: %d\n", (*new_exit_status()).is_ms);
		printf("after execute_cmd: %s\n", (*new_exit_status()).new_value);
		set_exit_status_env(data);
		data->cur.idx_cmd++;
	}
}
