/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:56:20 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/03 17:51:17 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	free_fd(t_data *data, int inc_tbl)
{
	int	inc_fd;

	if ((data->store.table + inc_tbl)->fd != NULL)
	{
		inc_fd = 0;
		while (inc_fd < (data->store.table + inc_tbl)->qty_cmd)
		{
			if (*((data->store.table + inc_tbl)->fd + inc_fd) != NULL)
				free(*((data->store.table + inc_tbl)->fd + inc_fd));
			inc_fd++;
		}
		free((data->store.table + inc_tbl)->fd);
		(data->store.table + inc_tbl)->fd = NULL;
	}
}

void	execute_table(t_data *data)
{
	int	inc_tbl;

	inc_tbl = 0;
	while (inc_tbl < data->store.qty_tbl)
	{
		data->cur.table = (data->store.table + inc_tbl);
		initialize_fd(data);
		execute_cmd(data);
		free_fd(data, inc_tbl);
		if ((data->store.table + inc_tbl)->delimiter == DELIMITER_AND
			&& data->exit_status != EXIT_SUCCESS)
			break ;
		if ((data->store.table + inc_tbl)->delimiter == DELIMITER_OR
			&& data->exit_status == EXIT_SUCCESS)
			break ;
		inc_tbl++;
	}
}
