/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:35:04 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/07 17:18:03 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	execve_error(t_data *data)
{
	if (errno == EACCES)
	{
		write_str("Permission denied\n");
		write_str(*data->cur.cmd->token);
		write_str("\n");
		exit(EXIT_CMD_INTERRUPTED);
	}
	else if (errno == ENOENT)
	{
		if (ft_strcmp(*data->cur.cmd->token, "exit") != 0)
		{
			write_str("Command not found: ");
			write_str(*data->cur.cmd->token);
			write_str("\n");
		}
		exit(EXIT_CMD_NOT_FOUND);
	}
	kill(getpid(), SIGKILL);
}
