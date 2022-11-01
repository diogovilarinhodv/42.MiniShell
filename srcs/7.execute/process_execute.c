/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:15:10 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/01 11:35:18 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	process_execute(t_data *data)
{
	while (data->cur.idx_cmd < data->cur.table->qty_cmd)
	{
		*(data->tmp.pid + data->cur.idx_cmd) = fork();
		if (*(data->tmp.pid + data->cur.idx_cmd) == 0)
			children_process(data);
		data->cur.idx_cmd++;
	}
}