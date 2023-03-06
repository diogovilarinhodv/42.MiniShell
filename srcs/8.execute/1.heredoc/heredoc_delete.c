/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:22:53 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/05 20:56:00 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	delete_heredoc(t_data *data)
{
	int		pid;
	int		wait_status;
	char	**args;

	data->cur.cmd->is_heredoc = NO;
	args = malloc(sizeof(char *) * 3);
	*args = ft_strdup("/usr/bin/rm");
	*(args + 1) = ft_strdup("tmp_file");
	*(args + 2) = NULL;
	wait_status = 0;
	pid = fork();
	if (pid == 0)
	{
		close_all_fd(data);
		if (execve(*args, args, NULL) == -1)
			kill(getpid(), SIGKILL);
	}
	close_fd(data);
	waitpid(pid, &wait_status, 0);
	free(*(args + 1));
	free(*args);
	free(args);
}
