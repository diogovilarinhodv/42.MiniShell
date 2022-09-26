/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:01:54 by dpestana          #+#    #+#             */
/*   Updated: 2022/09/26 11:51:26 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
// ping -c 5 google.com | grep rtt
static	void	execute_non_builtin(char *cmd, t_data *data)
{
	int	id;

	id = fork();
	if (id == 0)
	{
		if (data->tmp.idx < data->line.qty_pipes && data->line.qty_pipes > 0 && data->tmp.idx == 0)
		{
			printf("first cmd 1 \n\n");
			dup2(data->tmp.fd[1], STDOUT_FILENO);
			printf("first cmd 2 \n\n");
		}
		else if (data->tmp.idx < data->line.qty_pipes && data->line.qty_pipes > 0)
		{
			printf("second cmd 1 \n\n");
			dup2(data->tmp.fd[0], STDIN_FILENO);
			dup2(data->tmp.fd[1], STDOUT_FILENO);
			printf("second cmd 2 \n\n");
		}
		else if (data->tmp.idx == data->line.qty_pipes && data->line.qty_pipes > 0)
		{
			printf("third cmd 1 \n\n");
			dup2(data->tmp.fd[0], STDIN_FILENO);
			printf("third cmd 2 \n\n");
		}
		close(data->tmp.fd[0]);
		close(data->tmp.fd[1]);
		if (execve(cmd, data->tmp.cmd->token, NULL) == -1)
			kill(getpid(), SIGKILL);
	}
	if (id != 0)
		wait(0);
}

void	non_builtin(t_data *data)
{
	char	*cmd;

	cmd = ft_strjoin("/bin/", *data->tmp.cmd->token);
	execute_non_builtin(cmd, data);
	if (cmd != NULL)
		free(cmd);
}
