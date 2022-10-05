/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:01:54 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/04 12:31:42 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
// ping -c 5 google.com | grep rtt

static void	fd_non_builtin(t_data *data)
{
	if (data->tmp.idx < data->line.qty_pipes && data->line.qty_pipes > 0 && data->tmp.idx == 0)
		dup2(data->tmp.fd[1], STDOUT_FILENO);
	else if (data->tmp.idx < data->line.qty_pipes && data->line.qty_pipes > 0)
	{
		dup2(data->tmp.fd[0], STDIN_FILENO);
		dup2(data->tmp.fd[1], STDOUT_FILENO);
	}
	else if (data->tmp.idx == data->line.qty_pipes && data->line.qty_pipes > 0)
		dup2(data->tmp.fd[0], STDIN_FILENO);
}

static	void execute_non_builtin(char *cmd, t_data *data)
{
	close(data->tmp.fd[0]);
	close(data->tmp.fd[1]);
	if (execve(cmd, data->tmp.cmd->token, NULL) == -1)
		kill(getpid(), SIGKILL);
}

static void	free_non_builtin(char *cmd)
{
	if (cmd != NULL)
	{
		free(cmd);
		cmd = NULL;
	}
}

void	non_builtin(t_data *data)
{
	char	*cmd;

	cmd = ft_strjoin("/bin/", *data->tmp.cmd->token);
	fd_non_builtin(data);
	execute_non_builtin(cmd, data);
	free_non_builtin(cmd);
}
