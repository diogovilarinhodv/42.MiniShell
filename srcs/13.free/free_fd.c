/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:02:08 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/09 13:22:36 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	free_fd(t_data *data)
{
	int	inc_tbl;
	int	inc_fd;

	inc_tbl = 0;
	while (inc_tbl < data->store.qty_tbl)
	{
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
		inc_tbl++;
	}
	data->cur.idx_cmd = 0;
}