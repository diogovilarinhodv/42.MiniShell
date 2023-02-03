/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:18:53 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/03 17:52:22 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static int	open_file(char *filename, int type)
{
	int	fd;

	fd = -1;
	if (type == LEFT_ARROW)
	{
		fd = open(filename, O_RDONLY, 0);
		if (fd != -1)
			dup2(fd, STDIN_FILENO);
	}
	else if (type == RIGHT_ARROW)
	{
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd != -1)
			dup2(fd, STDOUT_FILENO);
	}
	else if (type == DOUBLE_RIGHT_ARROW)
	{
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
		if (fd != -1)
			dup2(fd, STDOUT_FILENO);
	}
	if (fd != -1)
		close(fd);
	return (fd);
}

void	set_redirects(t_data *data)
{
	int		inc;
	t_red	*cur_red;

	inc = 0;
	if (data->cur.cmd->qty_red < 1)
	{
		data->exit_status = EXIT_SUCCESS;
		return ;
	}
	while (inc < data->cur.cmd->qty_red)
	{
		cur_red = (data->cur.cmd->red + inc);
		if (open_file(cur_red->token, cur_red->type) == -1)
		{
			data->exit_status = errno;
			return ;
		}
		inc++;
	}
	data->exit_status = EXIT_SUCCESS;
}
