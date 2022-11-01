/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:06:13 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/01 10:37:48 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	inicialize_fd(t_data *data)
{
	int	inc;

	inc = 0;
	data->tmp.fd = malloc(sizeof(int *) * data->cur.table->qty_cmd);
	while (inc < data->cur.table->qty_cmd)
	{
		*(data->tmp.fd + inc) = malloc(sizeof(int) * 2);
		pipe(*(data->tmp.fd + inc));
		inc++;
	}
}