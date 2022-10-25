/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:02:08 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/24 18:56:23 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	free_tmp(t_data *data)
{
	int	inc;
	int	inc2;

	inc = 0;
	inc2 = 0;
	if (data->tmp.cmd != NULL)
		data->tmp.cmd = NULL;
	if (data->tmp.pid != NULL)
	{
		free(data->tmp.pid);
		data->tmp.pid = NULL;
	}
	if (data->tmp.fd != NULL)
	{
		while (inc2 < data->store.qty_tbl)
		{
			while (inc < (data->store.table + inc2)->qty_cmd)
			{
				if (*(data->tmp.fd + inc) != NULL)
				{
					free(*(data->tmp.fd + inc));
					*(data->tmp.fd + inc) = NULL;
				}
				inc++;
			}
			inc2++;
		}
		free(data->tmp.fd);
		data->tmp.fd = NULL;
	}
	data->tmp.idx = 0;
}