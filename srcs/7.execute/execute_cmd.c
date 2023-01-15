/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:15:10 by dpestana          #+#    #+#             */
/*   Updated: 2023/01/15 20:05:09 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	execute_cmd(t_data *data)
{
	int	stored_stdin;
	int	stored_stdout;
	char	*str_exit_status;

	data->cur.idx_cmd = 0;
	while (data->cur.idx_cmd < data->cur.table->qty_cmd)
	{
		stored_stdin = dup(STDIN_FILENO);
		stored_stdout = dup(STDOUT_FILENO);
		data->cur.cmd = (data->cur.table->cmd + data->cur.idx_cmd);
		replace_tokens(data);
		set_redirects(data);
		if (data->exit_status == EXIT_SUCCESS)
		{
			if (builtins(data) == NO)
				non_builtin(data);
		}
		unset_env_var_full(data);
		dup2(stored_stdin, STDIN_FILENO);
		dup2(stored_stdout, STDOUT_FILENO);
		close(stored_stdin);
		close(stored_stdout);
		set_env(data, "_", *(data->cur.cmd->token + data->cur.cmd->qty_tkn - 1));
		str_exit_status = ft_itoa(data->exit_status);
		set_env(data, "?", str_exit_status);
		free(str_exit_status);
		data->cur.idx_cmd++;
	}
}
