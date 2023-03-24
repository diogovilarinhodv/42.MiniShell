/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:35:04 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/23 15:18:52 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	exec_enoent_error(t_data *data)
{
	int	len;

	len = ft_strlen(*data->cur.cmd->token);
	if (ft_strcmp(*data->cur.cmd->token, "exit") != 0)
	{
		if (*(*data->cur.cmd->token + len - 1) == '/')
		{
			write_str(*data->cur.cmd->token);
			write_str(": No such file or directory");
			write_str("\n");
		}
		else
		{
			write_str("Command not found: ");
			write_str(*data->cur.cmd->token);
			write_str("\n");
		}
	}
	exit(EXIT_CMD_NOT_FOUND);
}

static void	write_error(char *msg, char *str, int n)
{
	write_str(str);
	write_str(msg);
	write_str("\n");
	exit(n);
}

void	execve_error(t_data *data)
{
	struct stat	buf;
	DIR			*dir;
	char		*str;

	str = *data->cur.cmd->token;
	if (errno == EACCES)
	{
		if (**data->cur.cmd->token == '\0')
			write_error(": Command not found", str, EXIT_CMD_NOT_FOUND);
		lstat(*data->cur.cmd->token, &buf);
		if (S_ISDIR(buf.st_mode))
			write_error(": Is a directory", str, EXIT_CMD_IS_DIRECTORY);
		dir = opendir(*data->cur.cmd->token);
		if (dir)
		{
			closedir(dir);
			write_error(": Is a directory", str, EXIT_CMD_IS_DIRECTORY);
		}
		else
			write_error(": Permission denied", str, EXIT_CMD_INTERRUPTED);
	}
	else if (errno == ENOENT)
		exec_enoent_error(data);
	exit(EXIT_FAILURE);
}
