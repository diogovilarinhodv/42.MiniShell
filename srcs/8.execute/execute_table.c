/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:56:20 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/07 08:40:55 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	execute_table(t_data *data)
{
	int	inc_tbl;

	inc_tbl = 0;
	while (inc_tbl < data->store.qty_tbl)
	{
		data->cur.table = (data->store.table + inc_tbl);
		initialize_fd(data);
		execute_cmd(data);
		free_table_fd(data, inc_tbl);
		if (exit_table(data, inc_tbl) == YES)
			break ;
		inc_tbl++;
	}
}
