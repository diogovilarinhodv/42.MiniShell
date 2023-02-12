/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:35:04 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/12 17:41:05 by dpestana         ###   ########.fr       */
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
	}
	else if (errno == ENOENT
		&& ft_strcmp(*data->cur.cmd->token, "exit") != 0)
	{
		write_str("Command not found: ");
		write_str(*data->cur.cmd->token);
		write_str("\n");
	}
	if (errno == EACCES)
		exit(EXIT_CMD_INTERRUPTED);
	else if (errno == ENOENT)
		exit(EXIT_CMD_NOT_FOUND);
	kill(getpid(), SIGKILL);
}
