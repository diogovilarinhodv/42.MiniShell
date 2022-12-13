/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:34:21 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 04:13:42 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	set_cur(t_data *data)
{
	if (data->store.qty_tbl > 0)
	{
		data->cur.table = (data->store.table + data->store.qty_tbl - 1);
		if (data->cur.table->qty_cmd > 0)
			data->cur.cmd = (data->cur.table->cmd + data->cur.table->qty_cmd - 1);
	}
}
