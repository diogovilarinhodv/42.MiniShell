/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dup2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:45:56 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/05 21:31:42 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	set_dup2(t_data *data)
{
	if (data->cur.idx_cmd < (data->store.table->qty_cmd - 1) && data->store.table->qty_cmd > 0 && data->cur.idx_cmd == 0)
	{
		printf("1.a\n");
		dup2(data->tmp.fd[data->cur.idx_cmd][1], STDOUT_FILENO);
	}
	else if (data->cur.idx_cmd < (data->store.table->qty_cmd - 1) && data->store.table->qty_cmd > 0)
	{
		printf("2.a\n");
		dup2(data->tmp.fd[data->cur.idx_cmd - 1][0], STDIN_FILENO);
		dup2(data->tmp.fd[data->cur.idx_cmd][1], STDOUT_FILENO);
	}
	else if (data->cur.idx_cmd == (data->store.table->qty_cmd - 1) && data->store.table->qty_cmd > 0)
	{
		printf("3.a\n");
		dup2(data->tmp.fd[data->cur.idx_cmd - 1][0], STDIN_FILENO);
	}
}