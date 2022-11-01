/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:56:20 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/01 11:29:12 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	execute(t_data *data)
{
	int	inc_table;

	inc_table = 0;
	while (inc_table < data->store.qty_tbl)
	{
		data->tmp.fd = NULL;
		data->cur.idx_cmd = 0;
		data->cur.table = (data->store.table + inc_table);
		data->tmp.pid = malloc(sizeof(int) * data->cur.table->qty_cmd);
		inicialize_fd(data);
		process_execute(data);
		process_wait(data);
		close_fd(data);
		free_pid(data);
		free_fd(data);
		inc_table++;
	}
}
