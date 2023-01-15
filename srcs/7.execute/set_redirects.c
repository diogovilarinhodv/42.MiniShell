/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:18:53 by dpestana          #+#    #+#             */
/*   Updated: 2023/01/15 22:04:44 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static int	open_file(char *filename, int type)
{
	int	fd;

	if (type == LEFT_ARROW)
	{
		fd = open(filename, O_RDONLY, 0);
		if (fd != -1)
		{
			dup2(fd, STDIN_FILENO);
			close(fd);
		}
	}
	else if (type == RIGHT_ARROW)
	{
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd != -1)
		{
			dup2(fd, STDOUT_FILENO);
			close(fd);
		}
	}
	else if (type == DOUBLE_RIGHT_ARROW)
	{
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
		if (fd != -1)
		{
			dup2(fd, STDOUT_FILENO);
			close(fd);
		}
	}
	return (fd);
}

void	set_redirects(t_data *data)
{
	int	inc;

	inc = 0;
	if (data->cur.cmd->qty_red < 1)
	{
		data->exit_status = EXIT_SUCCESS;
		return ;
	}
	while (inc < data->cur.cmd->qty_red)
	{
		if (open_file((data->cur.cmd->red + inc)->token, (data->cur.cmd->red + inc)->type) == -1)
		{
			data->exit_status = errno;
			return ;
		}
		inc++;
	}
	data->exit_status = EXIT_SUCCESS;
}
