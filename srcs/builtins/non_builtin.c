/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:01:54 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/03 11:17:40 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
// ping -c 5 google.com | grep rtt

static void	execute_dup2(t_data *data)
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

static	void	execute_non_builtin(char *cmd, t_data *data)
{
	
	execute_dup2(data);
	close(data->tmp.fd[0]);
	close(data->tmp.fd[1]);
	printf("what1\n");
	if (execve(cmd, data->tmp.cmd->token, NULL) == -1)
		kill(getpid(), SIGKILL);
}

void	non_builtin(t_data *data)
{
	char	*cmd;

	cmd = ft_strjoin("/bin/", *data->tmp.cmd->token);
	execute_non_builtin(cmd, data);
	if (cmd != NULL)
	{
		free(cmd);
		cmd = NULL;
	}
}
