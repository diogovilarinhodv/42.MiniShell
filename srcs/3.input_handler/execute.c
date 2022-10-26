/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:56:20 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/12 18:15:16 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	execute(t_data *data)
{
	int	inc_table;

	inc_table = 0;
	while (inc_table < data->store.qty_tbl)
	{
		inicialize_tmp(data);
		data->cur.table = (data->store.table + data->store.qty_tbl);
		inicialize_pipes(data);
		process_execute(data);
		close_fds(data);
		wait_processes(data);
		free_tmp(data);
		inc_table++;
	}
}
