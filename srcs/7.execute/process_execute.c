/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:15:10 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/06 11:48:16 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	process_execute(t_data *data)
{
	int def_stdin;
	int	def_stdout;

	data->cur.idx_cmd = 0;
	while (data->cur.idx_cmd < data->cur.table->qty_cmd)
	{
		data->cur.cmd = (data->cur.table->cmd + data->cur.idx_cmd);
		replace_tokens(data);
		def_stdin = dup(STDIN_FILENO);
		def_stdout = dup(STDOUT_FILENO);
		// set_pipes();
		// set_redirects();
		if (data->exit_status == SUCCESS && data->cur.cmd->qty_tkn > 0)
		{
			if (builtins(data) == NO)
				non_builtin(data);
		}
		dup2(def_stdin, STDIN_FILENO);
		dup2(def_stdout, STDOUT_FILENO);
		close(def_stdin);
		close(def_stdout);
		data->cur.idx_cmd++;
	}
}