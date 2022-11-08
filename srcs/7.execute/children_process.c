/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:24:06 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/08 16:57:43 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	children_process(t_data *data)
{
	signal(SIGINT, SIG_DFL);
	close_fd(data);
	set_path(data);
	if (execve(*data->cur.cmd->token, data->cur.cmd->token, NULL) == -1)
		kill(getpid(), SIGKILL);
	// remove if and kill, and put errors msgs and exit
}