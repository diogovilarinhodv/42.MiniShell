/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize_pipes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:06:13 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/22 13:10:39 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	inicialize_pipes(t_data *data)
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