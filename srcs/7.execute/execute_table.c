/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:56:20 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/04 20:20:59 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	execute_table(t_data *data)
{
	int	inc_table;

	inc_table = 0;
	while (inc_table < data->store.qty_tbl)
	{
		data->cur.table = (data->store.table + inc_table);
		inicialize_fd(data);
		execute_cmd(data);
		free_fd(data);
		inc_table++;
	}
}
