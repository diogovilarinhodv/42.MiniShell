/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dup2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:45:56 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/22 13:12:06 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	set_dup2(t_data *data)
{
	if (data->cur.idx_cmd < data->store.table->qty_pipes && data->store.table->qty_pipes > 0 && data->cur.idx_cmd == 0)
	{
		dup2(data->tmp.fd[data->cur.idx_cmd][1], STDOUT_FILENO);
	}
	else if (data->cur.idx_cmd < data->store.table->qty_pipes && data->store.table->qty_pipes > 0)
	{
		dup2(data->tmp.fd[data->cur.idx_cmd - 1][0], STDIN_FILENO);
		dup2(data->tmp.fd[data->cur.idx_cmd][1], STDOUT_FILENO);
	}
	else if (data->cur.idx_cmd == data->store.table->qty_pipes && data->store.table->qty_pipes > 0)
	{
		dup2(data->tmp.fd[data->cur.idx_cmd - 1][0], STDIN_FILENO);
	}
	close_fds(data);
}