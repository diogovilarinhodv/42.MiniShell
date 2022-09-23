/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:01:54 by dpestana          #+#    #+#             */
/*   Updated: 2022/09/23 15:53:51 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static	void	execute_non_builtin(char *cmd, t_data *data)
{
	int	id;

	id = fork();
	if (id == 0)
	{
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
