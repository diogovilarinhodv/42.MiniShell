/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:18:53 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 04:09:33 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static int	open_file(char *filename, int type)
{
	int	fd;

	if (type == LEFT_ARROW)
	{
		fd = open(filename, O_RDONLY, 0);
		dup2(fd, STDIN_FILENO);
	}
	else if (type == RIGHT_ARROW)
	{
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		dup2(fd, STDOUT_FILENO);
	}
	else if (type == DOUBLE_RIGHT_ARROW)
	{
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
		dup2(fd, STDOUT_FILENO);
	}
	close(fd);
	return (fd);
}

void	set_redirects(t_data *data)
{
	int	inc;

	inc = 0;
	if (data->cur.cmd->qty_red < 1)
		return ;
	while (inc < data->cur.cmd->qty_red)
	{
		open_file((data->cur.cmd->red + inc)->token, (data->cur.cmd->red + inc)->type);
		inc++;
	}
}
