/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:33:37 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/07 08:34:38 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	free_table_fd(t_data *data, int inc_tbl)
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
