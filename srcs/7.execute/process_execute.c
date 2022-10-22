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
	data->tmp.pid = malloc(sizeof(int) * data->store.table->qty_cmd);
	while (data->tmp.idx < data->store.table->qty_cmd)
	{
		*(data->tmp.pid + data->tmp.idx) = fork();
		children_process(data);
		data->tmp.idx++;
	}
}