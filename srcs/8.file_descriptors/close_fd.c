/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:17:05 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 04:12:37 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	close_fd(t_data *data)
{
	if (data->cur.table->qty_cmd == 1 && data->cur.idx_cmd == 0)
	{
		close(data->store.table->fd[0][0]);
		close(data->store.table->fd[0][1]);
	}
	else if (data->cur.table->qty_cmd > 1 && data->cur.idx_cmd != 0)
	{
		if (data->cur.idx_cmd <= data->cur.table->qty_cmd - 1)
		{
			close(data->store.table->fd[data->cur.idx_cmd - 1][0]);
			close(data->store.table->fd[data->cur.idx_cmd - 1][1]);
		}
		if (data->cur.idx_cmd == data->cur.table->qty_cmd - 1)
		{
			close(data->store.table->fd[data->cur.idx_cmd][0]);
			close(data->store.table->fd[data->cur.idx_cmd][1]);
		}
	}
}
