/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:15:10 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/21 11:44:55 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	process_execute(t_data *data)
{
	data->tmp.pid = malloc(sizeof(int) * data->table.qty_cmd);
	while (data->tmp.idx < data->table.qty_cmd)
	{
		*(data->tmp.pid + data->tmp.idx) = fork();
		children_process(data);
		data->tmp.idx++;
	}
}