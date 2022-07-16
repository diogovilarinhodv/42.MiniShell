/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:01:54 by dpestana          #+#    #+#             */
/*   Updated: 2022/07/16 17:00:38 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static	void	inicialize_non_builtin(t_data *data, char **cmd, char ***args)
{
	int		inc;
	
	*cmd = ft_strjoin("/bin/", data->input.cmd);
	*args = malloc(sizeof(char **) * (data->input.qty_args + 1));
	inc = 0;
	while (inc < data->input.qty_args + 1)
	{
		if (inc == 0)
			**args = *cmd;
		else
			*(*args + inc) = *(data->input.args + inc - 1);
		inc++;
	}
}

static	void	execute_non_builtin(char *cmd, char **args)
{
	int	id;

	id = fork();
	if (id == 0)
	{
		if (execve(cmd, args, NULL) == -1)
			kill(getpid(), SIGKILL);
	}
	if (id != 0)
		wait(0);
}

static	void	freedom_non_builtin(char *cmd, char **args)
{
	if (cmd != NULL)
		free(cmd);
	if (args != NULL)
		free(args);
}

void	non_builtin(t_data *data)
{
	char	*cmd;
	char	**args;
	
	cmd = NULL;
	args = NULL;
	inicialize_non_builtin(data, &cmd, &args);
	execute_non_builtin(cmd, args);
	freedom_non_builtin(cmd, args);
}
