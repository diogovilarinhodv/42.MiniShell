/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:24:06 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/14 03:15:28 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	children_process(t_data *data)
{
	set_dup2(data);
	signal(SIGINT, SIG_DFL);
	close_all_fd(data);
	path_handler(data);
	if (execve(*data->cur.cmd->token, data->cur.cmd->token, NULL) == -1)
		kill(getpid(), SIGKILL);
}
