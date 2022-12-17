/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:06:13 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/14 02:05:28 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	initialize_fd(t_data *data)
{
	int	inc;

	inc = 0;
	data->cur.table->fd = malloc(sizeof(int *) * data->cur.table->qty_cmd);
	while (inc < data->cur.table->qty_cmd)
	{
		*(data->cur.table->fd + inc) = malloc(sizeof(int) * 2);
		pipe(*(data->cur.table->fd + inc));
		inc++;
	}
}
