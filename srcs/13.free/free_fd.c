/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:02:08 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/01 11:23:56 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	free_fd(t_data *data)
{
	int	inc;
	int	inc2;

	inc2 = 0;
	if (data->tmp.fd != NULL)
	{
		while (inc2 < data->store.qty_tbl)
		{
			inc = 0;
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
	data->cur.idx_cmd = 0;
}