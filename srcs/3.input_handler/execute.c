/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:56:20 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/09 13:38:13 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	execute(t_data *data)
{
	int	inc_table;

	inc_table = 0;
	while (inc_table < data->store.qty_tbl)
	{
		data->cur.table = (data->store.table + inc_table);
		inicialize_fd(data);
		process_execute(data);
		close_fd(data);
		free_fd(data);
		inc_table++;
	}
}
