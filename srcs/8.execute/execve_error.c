/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:35:04 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/24 15:07:05 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	write_error(t_data *data, char *msg, char *str, int n)
{
	write_str(str);
	write_str(msg);
	write_str("\n");
	unset_env_var_full(data);
	close(data->stdin_saved);
	close(data->stdout_saved);
	close_all_fd(data);
	end_program(data, n);
}

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
	unset_env_var_full(data);
	close(data->stdin_saved);
	close(data->stdout_saved);
	close_all_fd(data);
	end_program(data, EXIT_CMD_NOT_FOUND);
}

static void	exec_eacces_error(t_data *data, char *str)
{
	struct stat	buf;
	DIR			*dir;

	if (**data->cur.cmd->token == '\0')
		write_error(data, ": Command not found", str, EXIT_CMD_NOT_FOUND);
	lstat(*data->cur.cmd->token, &buf);
	if (S_ISDIR(buf.st_mode))
		write_error(data, ": Is a directory", str, EXIT_CMD_IS_DIRECTORY);
	dir = opendir(*data->cur.cmd->token);
	if (dir)
	{
		closedir(dir);
		write_error(data, ": Is a directory", str, EXIT_CMD_IS_DIRECTORY);
	}
	else
		write_error(data, ": Permission denied", str, EXIT_CMD_INTERRUPTED);
}

void	execve_error(t_data *data)
{
	char		*str;

	str = *data->cur.cmd->token;
	if (errno == EACCES)
		exec_eacces_error(data, str);
	else if (errno == ENOENT)
		exec_enoent_error(data);
	unset_env_var_full(data);
	close(data->stdin_saved);
	close(data->stdout_saved);
	close_all_fd(data);
	end_program(data, EXIT_FAILURE);
}
