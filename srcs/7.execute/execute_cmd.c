/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:15:10 by dpestana          #+#    #+#             */
/*   Updated: 2023/01/01 15:23:48 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	execute_cmd(t_data *data)
{
	int	stored_stdin;
	int	stored_stdout;

	data->cur.idx_cmd = 0;
	while (data->cur.idx_cmd < data->cur.table->qty_cmd)
	{
		if (data->exit_status == EXIT_FAILURE)
			break ;
		stored_stdin = dup(STDIN_FILENO);
		stored_stdout = dup(STDOUT_FILENO);
		data->cur.cmd = (data->cur.table->cmd + data->cur.idx_cmd);
		replace_tokens(data);
		set_redirects(data);
		if (builtins(data) == NO)
			non_builtin(data);
		unset_env_var_full(data);
		dup2(stored_stdin, STDIN_FILENO);
		dup2(stored_stdout, STDOUT_FILENO);
		close(stored_stdin);
		close(stored_stdout);
		data->cur.idx_cmd++;
	}
}
