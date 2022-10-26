/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:15:10 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/22 13:10:39 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	process_execute(t_data *data)
{
	data->tmp.pid = malloc(sizeof(int) * data->cur.table->qty_cmd);
	data->cur.idx_cmd = 0;
	while (data->cur.idx_cmd < data->cur.table->qty_cmd)
	{
		*(data->tmp.pid + data->cur.idx_cmd) = fork();
		children_process(data);
		data->cur.idx_cmd++;
	}
}