/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:02:08 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/12 18:24:36 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	free_tmp(t_data *data)
{
	int	inc;

	inc = 0;
	if (data->tmp.cmd != NULL)
		data->tmp.cmd = NULL;
	if (data->tmp.pid != NULL)
	{
		free(data->tmp.pid);
		data->tmp.pid = NULL;
	}
	if (data->tmp.fd != NULL)
	{
		while (inc < data->line.qty_cmd)
		{
			if (*(data->tmp.fd + inc) != NULL)
			{
				free(*(data->tmp.fd + inc));
				*(data->tmp.fd + inc) = NULL;
			}
			inc++;
		}
		free(data->tmp.fd);
		data->tmp.fd = NULL;
	}
	data->tmp.idx = 0;
}